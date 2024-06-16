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
"!=" { return DIFERENTE;}
"<" { return MENOR; }
">" { return MAIOR; }
"<=" { return MENORIGUAL; }
">=" { return MAIORIGUAL; }
"%" { return PORCENTO; }
")" { return LPAR; }
"(" { return RPAR; }
";" { return PEV; }
"/" { return DIV; }
"*" { return MULT;}
"&&" {return AND;}
"||" {return OR;}
"\!" {return NOT;}
"++" { return MAISMAIS; }
"--" { return MENOSMENOS; }
"}" { return LCHAVES; }
"{" { return RCHAVES; }
"]" { return LCOLCHETES;}
"[" { return RCOLCHETES;}
"," { return VIRGULA; }
"\"" { return ASPASDUPLAS; }
"ftnirp" { return PRINTF; }
"fnacs" { return SCANF; }
"tni" { return INT; }
"taolf" { return FLOAT; }
"rahc" { return CHAR; }
"elihw" { return WHILE; }
"esle" { return ELSE; }
"rof" { return FOR; }
"fi" { return IF; }
[0-9]+ { 
    yylval.int_val = atoi(yytext);
    return NUM; 
}
-?[0-9]+ { // ? indica que o - é optativo
    yylval.int_val = atoi(yytext);
    return NUM;
}
[a-zA-Z][a-zA-Z0-9_]* { 
    yylval.str_val = strdup(yytext);
    return ID; 
    }
\"[^"]*\" {
    yylval.str_val = strdup(yytext);
    return STRING;
}

"//".*"\n" { }
" " {}
"\t" {}
"\n" {}
"\0" {}
"\a" {}
"\b" {}
"\f" {}
"\r" {}
. { fprintf(stderr, "Caractere inválido encontrado %s\n", yytext); }
%%