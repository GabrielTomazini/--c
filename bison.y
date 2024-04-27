%{
#include <stdio.h>
int yylex(void);
void yyerror(char *s);
%}

/* lista de tokens -- o bison ira gerar o tipo enum com essa lista */
%token MAIS
%token MENOS
%token MENOR
%token MAIOR
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
%token LETRA
%token NUM
%token ID
%token IGUAL
%token ATRIB
%token DIV
%token IF
%token WHILE
%token CHAR
%token INT
%token FLOAT
%token PRINTF
%token ASPASDUPLAS
%token VIRGULA
%token SCANF
%token ABRECOMENTARIO
%token FECHACOMENTARIO
%token LCOLCHETES
%token RCOLCHETES
%token BARRABARRA

%define parse.error verbose

%%

codigos : codigo 
        | codigo codigos;
codigo : atrib
       | laco
       | condicional
       | declara
       | print
       | read
       | comentario
       ;

atrib : ID ATRIB expr PEV 
      | ID LCOLCHETES NUM RCOLCHETES ATRIB expr PEV
      ;
expr : expr MAIS termo
     | expr MENOS termo
     | termo ;
termo : termo DIV fator
      | termo PORCENTO fator
      | fator ;
fator : ID
      | NUM
      | LETRA
      | LPAR expr RPAR
      | LCHAVES expr RCHAVES;

condicional : IF LPAR condicao RPAR LCHAVES codigos RCHAVES
            | IF LPAR condicao RPAR codigo
            | IF LPAR condicao RPAR LCHAVES codigos RCHAVES ELSE LCHAVES codigos RCHAVES
            | IF LPAR condicao RPAR LCHAVES codigos RCHAVES ELSE codigo;

condicao : ID
         | ID comparacao expr
         ;

comparacao : IGUAL 
           | MAIOR IGUAL
           | MENOR IGUAL
           | MAIOR
           | MENOR;

cremento : MAISMAIS
         | MENOSMENOS;

laco : FOR LPAR atrib fator comparacao fator PEV ID cremento RPAR LCHAVES codigos RCHAVES
     | FOR LPAR atrib fator comparacao fator PEV ID cremento RPAR codigos PEV
     | WHILE LPAR fator comparacao fator RPAR LCHAVES codigos RCHAVES
     | WHILE LPAR ID RPAR LCHAVES codigos RCHAVES
     ;

declara : tipo ID PEV
        | tipo ID LCOLCHETES NUM RCOLCHETES PEV
        | tipo atrib
        ;

tipo : CHAR
     | INT
     | FLOAT;

print : PRINTF LPAR mensagem RPAR PEV
      ;

mensagem : ASPASDUPLAS fatores ASPASDUPLAS
         ;


fatores : fator fatores
        | fator
        ;

read : SCANF LPAR mensagem VIRGULA ID RPAR PEV
     | SCANF LPAR ID RPAR PEV
     ;

comentario : ABRECOMENTARIO fatores FECHACOMENTARIO
           | BARRABARRA fatores 
           ;


%%

int main(int argc, char *argv[]) {

    yyparse();

    return 0;
}

void yyerror(char *s) { fprintf(stderr, "ERRO Sintatico: %s\n", s); }
