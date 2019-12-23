%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "include/alfa.h"
    #include "y.tab.h"

    int line = 1, col = 1, error = 0;
%}
%option noyywrap
%%

"\n" {line++; col=1;}
"\t" {col+=yyleng;}
" " {col+=yyleng;}
"\r" {col+=yyleng;}
"//".*\n {line++;}
main {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MAIN;}
int {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_INT;}
boolean {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_BOOLEAN;}
array {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_ARRAY;}
function {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_FUNCTION;}
if {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_IF;}
else {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_ELSE;}
while {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_WHILE;}
scanf {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_SCANF;}
printf {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_PRINTF;}
return {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_RETURN;}
true {col+=yyleng;yylval.atributos.valor_entero = 1;fprintf(stdout,";D:\t%s\n",yytext); return TOK_TRUE;}
false {col+=yyleng;yylval.atributos.valor_entero = 0;fprintf(stdout,";D:\t%s\n",yytext); return TOK_FALSE;}
";" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_PUNTOYCOMA;}
"," {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_COMA;}
"(" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_PARENTESISIZQUIERDO;}
")" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_PARENTESISDERECHO;}
"[" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_CORCHETEIZQUIERDO;}
"]" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_CORCHETEDERECHO;}
"{" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_LLAVEIZQUIERDA;}
"}" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_LLAVEDERECHA;}
"=" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_ASIGNACION;}
"+" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MAS;}
"-" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MENOS;}
"/" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_DIVISION;}
"*" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_ASTERISCO;}
"&&" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_AND;}
"||" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_OR;}
"!" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_NOT;}
"==" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_IGUAL;}
"!=" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_DISTINTO;}
"<=" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MENORIGUAL;}
">=" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MAYORIGUAL;}
"<" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MENOR;}
">" {col+=yyleng;fprintf(stdout,";D:\t%s\n",yytext); return TOK_MAYOR;}
[0-9]+ {col+=yyleng; yylval.atributos.valor_entero=atoi(yytext); fprintf(stdout,";D:\t%s\n",yytext); return TOK_CONSTANTE_ENTERA;}
[a-zA-Z][a-zA-Z0-9]* {col+=yyleng; strcpy(yylval.atributos.lexema, yytext); if(yyleng<=100){fprintf(stdout,";D:\t%s\n",yytext);}else{fprintf(stdout,"****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR;}; return TOK_IDENTIFICADOR;}
. {error=1; col+=yyleng; fprintf(stdout,"****Error morfologico en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); return TOK_ERROR;}
%%
