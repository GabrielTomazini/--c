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

typedef struct {
    int entrada;
    int saida;
} registradores;

typedef struct {
    int topo;
    registradores R[1000];
} Pilha;

// Vetor de simbolos (a tabela de simbolos em si)
Pilha *p;
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

simbolo tabsimb[1000];
int nsimbs = 0;
int auxEnd = 0;
// Dado um ID, busca na tabela de simbolos o endereço respectivo
int getendereco(char * id) {
    for (int i = 0; i < nsimbs; i++){
            if (!strcmp(tabsimb[i].id, id))
                return tabsimb[i].end;
    }
    return -1;
}
void push(Pilha *p,int entrada, int saida)
{
    p->topo++;
    p->R[p->topo].entrada = entrada;
    p->R[p->topo].saida = saida;
}
registradores pop(Pilha *p)
{
    if(p->topo==-1)
    {
        exit(1);
    }
    return p->R[p->topo--];
}

void erroSemantico(char *c) {
    if (getendereco(c) == -1) {
        //printf("printf \"Erro semantico, %s nao foi declarada\n\"", c);
        printf("Erro semantico, %s nao foi declarada\n", c);
        exit(1);
    }
}

void reDeclara(char *c){
    for (int i = 0; i < nsimbs; i++){
        if (!strcmp(tabsimb[i].id, c)){ 
            //printf("printf \"Erro semantico, %s nao pode ser redeclarada\" \n", c);
            printf("Erro semantico, %s nao pode ser redeclarada\n", c);
            exit(1);
        }
    }
}

/* Contador global de registradores temporarios */
int T=0;
/* Contador global de labels temporarios */
int S=0;

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
%type <int_val> condicional condicoes expr termo fator condicao codigos codigo atrib declara print read cremento laco cremento_for RPAR LPAR
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

declara : INT ID PEV { 
            reDeclara($2);
            tabsimb[nsimbs] = (simbolo){strdup($2), auxEnd}; 
            auxEnd++;
            nsimbs++; 
         }
        | INT ID LCOLCHETES NUM RCOLCHETES PEV {
            reDeclara($2);
            tabsimb[nsimbs] = (simbolo){strdup($2), auxEnd};
            auxEnd = auxEnd + $4; 
            nsimbs++;  
         }
        | INT ID ATRIB condicoes PEV { 
            reDeclara($2);
            tabsimb[nsimbs] = (simbolo){strdup($2), auxEnd}; 
            nsimbs++;
            auxEnd++;
            printf("mov %%r%d, %%t%d\n",getendereco($2),$4);
         }                            
        ;

atrib : ID ATRIB condicoes PEV { 
         erroSemantico($1);
         printf("mov %%r%d, %%t%d\n",getendereco($1),$3 );
        }
      | ID LCOLCHETES expr RCOLCHETES ATRIB condicoes PEV { 
         erroSemantico($1); 
         printf("store %%t%d, %%t%d(%d)\n",$6,$3,getendereco($1));
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

fator : ID { 
            erroSemantico($1); 
            //int end = getendereco($1);
            printf("mov %%t%d, %%r%d\n", T, getendereco($1));
            $$ = T++;
         }
        | NUM {
            printf("mov %%t%d, %d\n", T, $1);
            $$ = T++;
         }
        | LPAR condicoes RPAR {
            $$ = $2;
         } 
        | ID LCOLCHETES expr RCOLCHETES { 
            erroSemantico($1); 
            printf("load %%t%d, %%t%d(%d)\n",T,$3,getendereco($1));
            $$ = T++;
         }
        ;

condicional : IF LPAR condicoes {
                printf("jf %%t%d, R%d\n",$3,S);
                S++;
                push(p,S-1,S);
             } RPAR LCHAVES codigos RCHAVES else_optional {
                pop(p);
             }
            ;

else_optional : {
                printf("label R%d\n",p->R[p->topo].entrada);
               }
              | ELSE {
                printf("jump R%d\n",p->R[p->topo].saida);
                printf("label R%d\n",p->R[p->topo].entrada);
                S++; 
               } LCHAVES codigos RCHAVES {
                printf("label R%d\n",p->R[p->topo].saida);
               }
              ;

condicoes : condicao
          | condicao OR condicoes {
                printf("or %%t%d, %%t%d, %%t%d\n",T,$1,$3);
                $$=T++;
          }
          | condicao AND condicoes {
                printf("and %%t%d, %%t%d, %%t%d\n",T,$1,$3);
                $$=T++;
           }
          | NOT condicoes {
                printf("not %%t%d, %%t%d\n",T,$2);
                $$=T++;
           }
          ;

condicao : expr IGUAL expr {
            printf("equal %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr DIFERENTE expr {
            printf("diff %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr MAIORIGUAL expr {
            printf("greatereq %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr MENORIGUAL expr {
            printf("lesseq %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr MAIOR expr {
            printf("greater %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
         | expr MENOR expr {
            printf("less %%t%d, %%t%d, %%t%d\n", T, $1, $3);
            $$ = T++;
          }
            | expr
         ;

cremento_for : MAISMAIS {
                $$ = 1;
              }
             | MENOSMENOS {
                $$ = 2;
              }
             ;

cremento: ID MAISMAIS PEV {
            printf("add %%r%d, %%r%d, 1\n",getendereco($1),getendereco($1));
         }
        | ID MENOSMENOS PEV {
            printf("sub %%r%d, %%r%d, 1\n",getendereco($1),getendereco($1));
         }
        ;

laco : FOR LPAR atrib {
            printf("label R%d\n",S);
            S++;
            push(p,S-1,S);
         } 
        condicoes {
            printf("jf %%t%d, R%d\n",$5,S);   
            S++;   
         } 
        PEV ID cremento_for RPAR LCHAVES codigos {
            if($9==1)
            {
                printf("add %%r%d, %%r%d, 1\n",getendereco($8),getendereco($8));
            }else{
                printf("sub %%r%d, %%r%d, 1\n",getendereco($8),getendereco($8));
            }
            printf("jump R%d\n",p->R[p->topo].entrada);
         } RCHAVES {
            printf("label R%d\n",p->R[p->topo].saida);
            pop(p);
         }
        | WHILE {
            printf("label R%d\n",S);
            S++;
            push(p,S-1,S);
         } LPAR condicoes{
            printf("jf %%t%d, R%d\n",$4,S);
            S++;
         } RPAR LCHAVES codigos RCHAVES {
            printf("jump R%d\n",p->R[p->topo].entrada);
            printf("label R%d\n",p->R[p->topo].saida);
            pop(p);
         }
        ;

print : PRINTF LPAR STRING RPAR PEV {
            printf("printf %s\n",$3);
         }
        | PRINTF LPAR expr RPAR PEV {
            printf("printv %%t%d\n",$3);
         }
        ;

read : SCANF LPAR ID RPAR PEV {
        printf("read %%r%d\n", getendereco($3));
      }
     | SCANF LPAR ID LCOLCHETES expr RCOLCHETES RPAR PEV{
        printf("read %%t%d\n", T);
        printf("store %%t%d, %%t%d(%d)\n",T,$5,getendereco($3));
        T++;
      }
     ;

%%

int main(int argc, char *argv[]) {
    p = (Pilha *)malloc(sizeof(Pilha));
    inicializaPilha(p);
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
 
    yyparse();
    fclose(yyin);
    return 0;
}

void yyerror(const char *s) { fprintf(stderr, "ERRO Sintatico: %s\n", s); }