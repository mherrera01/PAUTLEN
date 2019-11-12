%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
extern FILE * salida;
%}
%option noyywrap

%%
main { fprintf(salida,"%s ",yytext); return TOK_MAIN; }
array { fprintf(salida,"%s ",yytext); return TOK_ARRAY; }
int { fprintf(salida,"%s ",yytext); return TOK_INT; }
if { fprintf(salida,"%s ",yytext); return TOK_IF; }
else { fprintf(salida,"%s ",yytext); return TOK_ELSE; }
while { fprintf(salida,"%s ",yytext); return TOK_WHILE; }
";" { fprintf(salida,"%s ",yytext); return TOK_PUNTOYCOMA; }
"(" { fprintf(salida,"%s ",yytext); return TOK_PARENTESISIZQUIERDO; }
")" { fprintf(salida,"%s ",yytext); return TOK_PARENTESISDERECHO; }
"*" { fprintf(salida,"%s ",yytext); return TOK_ASTERISCO; }
"+" { fprintf(salida,"%s ",yytext); return TOK_MAS; }
"<=" { fprintf(salida,"%s ",yytext); return TOK_MENORIGUAL; }
"{" { fprintf(salida,"%s ",yytext); return TOK_LLAVEIZQUIERDA; }
"}" { fprintf(salida,"%s ",yytext); return TOK_LLAVEDERECHA; }
[a-zA-Z][a-zA-Z0-9]* { fprintf(salida,"%s ",yytext); return TOK_IDENTIFICADOR; }
%%
int main()
{
return yylex();
}
