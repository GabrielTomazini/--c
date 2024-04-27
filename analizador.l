%{
#include <stdio.h>
#include "bison.tab.h" 
%}


%option noyywrap

%%
"+" { return MAIS; }
"-" { return MENOS; }
"==" { return IGUAL; }
"=" { return ATRIB; }
"<" { return MENOR; }
">" { return MAIOR; }
"%" { return PORCENTO; }
"(" { return LPAR; }
")" { return RPAR; }
";" { return PEV; }
"/" { return DIV; }
"++" { return MAISMAIS; }
"--" { return MENOSMENOS; }
"{" { return LCHAVES; }
"}" { return RCHAVES; }
"[" { return LCOLCHETES;}
"]" { return RCOLCHETES;}
"," { return VIRGULA; }
"\"" { return ASPASDUPLAS; }
"/*" { return ABRECOMENTARIO;}
"*/" { return FECHACOMENTARIO;}
"//" { return BARRABARRA;}
"printf" { return PRINTF; }
"scanf" { return SCANF; }
"string" {return STRING;}
"int" { return INT; }
"float" { return FLOAT; }
"char" { return CHAR; }
"while" { return WHILE; }
"else" { return ELSE; }
"for" { return FOR; }
"if" { return IF; }
'[a-zA-Z]' { return LETRA; }
[0-9]+ { return NUM; }
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
" " {}
"\n" {}
. { fprintf(stderr, "Caractere inválido encontrado %s\n", yytext); }
%%



