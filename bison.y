%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

// Um simbolo da tabela de simbolos é um id e seu endereço
typedef struct {
    char *id;
    int end;
} simbolo;

// Vetor de simbolos (a tabela de simbolos em si)
simbolo tabsimb[1000];
int nsimbs = 0;

// Dado um ID, busca na tabela de simbolos o endereço respectivo
int getendereco(char * id) {
    for (int i = 0; i < nsimbs; i++)
        if (!strcmp(tabsimb[i].id, id))
            return tabsimb[i].end;
    return -1;
}

void erroSemantico(char *c) {
    if (getendereco(c) == -1) {
        printf("Erro semantico, %s nao foi declarada\n", c);
        exit(1);
    }
}

/* Contador global de registradores temporarios */
int T=0;

%}

%union {
    char *str_val;
    int int_val;
}

/* lista de tokens -- o bison ira gerar o tipo enum com essa lista */
%token MAIS
%token MENOS
%token MENOR
%token MAIOR
%token MENORIGUAL
%token MAIORIGUAL
%token PORCENTO
%token LPAR
%token RPAR
%token PEV
%token MAISMAIS
%token MENOSMENOS
%token LCHAVES
%token RCHAVES
%token ELSE
%token FOR
%token AND
%token OR
%token NOT
%token <int_val>NUM
%token <str_val>ID
%token IGUAL
%token ATRIB
%token DIFERENTE
%token DIV
%token MULT
%token IF
%token WHILE
%token CHAR
%token <str_val>STRING
%token INT
%token FLOAT
%token PRINTF
%token ASPASDUPLAS
%token VIRGULA
%token SCANF
%token LCOLCHETES
%token RCOLCHETES
%token ESPECIAL

%define parse.error verbose
%type <int_val> condicional condicoes expr termo fator condicao codigos codigo atrib declara print read cremento laco 

%%

codigos : codigo 
        | codigo codigos
        ;

codigo : atrib
       | laco
       | condicional
       | declara
       | print
       | read
       | cremento
       ;

declara : INT ID PEV { tabsimb[nsimbs] = (simbolo){strdup($2), nsimbs}; nsimbs++; }
        | INT ID LCOLCHETES NUM RCOLCHETES PEV { tabsimb[nsimbs] = (simbolo){strdup($2), nsimbs}; nsimbs = nsimbs + $4; }
        | INT ID ATRIB expr PEV { tabsimb[nsimbs] = (simbolo){strdup($2), nsimbs}; nsimbs++;
                                                        printf("mov %%r%d, %%t%d\n",getendereco($2),$4);}
                                                       
        ;

atrib : ID ATRIB expr PEV  { 
         erroSemantico($1);
         printf("mov %%r%d, %%t%d\n",getendereco($1),$3 );
        }

      | ID LCOLCHETES expr RCOLCHETES ATRIB expr PEV { 
        erroSemantico($1); 
        printf("store %%t%d, %%t%d(%%r%d)",$6,$3,getendereco($1));
        }
      ;

expr : expr MAIS termo {
           printf("add %%t%d, %%t%d, %%t%d\n", T, $1, $3);
           $$ = T++;
       }

     | expr MENOS termo {
           printf("sub %%t%d, %%t%d, %%t%d\n", T, $1, $3);
           $$ = T++;
       }

     | termo { $$ = $1; }
     ;

termo : termo DIV fator {
           printf("div %%t%d, %%t%d, %%t%d\n", T, $1, $3);
           $$ = T++;
       }
      | termo MULT fator {
           printf("mult %%t%d, %%t%d, %%t%d\n", T, $1, $3);
           $$ = T++;
       }
      | termo PORCENTO fator {
           printf("mod %%t%d, %%t%d, %%t%d\n", T, $1, $3);
           $$ = T++;
       }
      | fator { $$ = $1; }
      ;

fator : ID  { 
            erroSemantico($1); 
            int end = getendereco($1);
            printf("mov %%t%d, %%r%d\n", T, end);
            $$ = T++;
            }

        | NUM {
            printf("mov %%t%d, %d\n", T, $1);
            $$ = T++;
         }

        | LPAR expr RPAR {
            $$ = $2;
         }

        | ID LCOLCHETES expr RCOLCHETES { 
            erroSemantico($1); 
            printf("load %%t%d, %%t%d(%%r%d)\n",T,$3,getendereco($1));
            $$ = T++;
         }
      ;
condicional : IF LPAR condicoes {printf("jf %%t%d, Relse\n",$3);}RPAR LCHAVES codigos{
                printf("jump Rfim\n");
            }
             RCHAVES else_optional
            {
                printf("label Rfim\n");
            }
            ;

else_optional :
              | ELSE
              {
                printf("label Relse\n");
              } LCHAVES codigos RCHAVES
              ;
condicoes : condicao
          {
              //  printf("jf %%t%d, diferente\n\n",T-1);
          }
          | condicao OR condicoes
          {
            printf("or %%t%d, %%t%d, %%t%d\n",T,$1,$3);
            $$=T++;
          }
          | condicao AND condicoes
          {
            printf("and %%t%d, %%t%d, %%t%d\n",T,$1,$3);
          }
          | NOT condicoes
          {
            printf("not %%t%d, %%t%d\n\n",T,$2);
          }
          ;

condicao : expr IGUAL expr {
            printf("equal %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ =T++;
         }
          
         | expr DIFERENTE expr {
                printf("diff %%t%d, %%t%d, %%t%d\n", T, $1, $3);
                $$ =T++;
         }
          
         | expr MAIORIGUAL expr {
            printf("greatereq %%t%d, %%t%d, %%t%d\n", T, $1, $3);
                $$ =T++;
         }
         | expr MENORIGUAL expr {
            printf("lesseq %%t%d, %%t%d, %%t%d\n", T, $1, $3);
                $$ =T++;
         }
         | expr MAIOR expr {
            printf("greater %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ =T++;
          }
         | expr MENOR expr {
            printf("less %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr
         ;

cremento : ID MAISMAIS
        {
        printf("add %%t%d, %%t%d, 1\n",getendereco($1)+1,getendereco($1)+1);
        printf("mov %%r%d, %%t%d\n",getendereco($1),getendereco($1)+1);
        }
         | ID MENOSMENOS
         {
        printf("sub %%t%d, %%t%d, 1\n",getendereco($1)+1,getendereco($1)+1);
        printf("mov %%r%d, %%t%d\n",getendereco($1),getendereco($1)+1);
         }
         ;

laco : FOR LPAR atrib {
    printf("label comeco\n");
} condicoes PEV cremento RPAR LCHAVES codigos RCHAVES
    {
        printf("\njump comeco\n");
        printf("label diferente\n");
        printf("jump fim\n");
        printf("\nlabel fim\n");
    }
     | while LPAR condicoes RPAR LCHAVES codigos RCHAVES
     {
        printf("jump comeco\n");
        printf("\nlabel diferente\n");
        printf("jump fim\n");
        printf("\nlabel fim\n");
     }
     ;

while : WHILE
    {
        printf("label comeco\n");
    }
     ;

print : PRINTF LPAR STRING RPAR PEV
        {
            printf("printf %s\n",$3);

        }
        | PRINTF LPAR expr RPAR PEV
        {
        printf("printv %%t%d\n",$3);
        }
        ;

read : SCANF LPAR ID RPAR PEV
        {
        printf("read %%r%d\n\n", getendereco($3));
        }
        ;

%%

int main(int argc, char *argv[]) {
    yyin = fopen("programa.cpp", "r");
    if (!yyin) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    yyparse();
    fclose(yyin);
    return 0;
}

void yyerror(const char *s) { fprintf(stderr, "ERRO Sintatico: %s\n", s); }