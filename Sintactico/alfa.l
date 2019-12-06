%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
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
main {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MAIN;}
int {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_INT;}
boolean {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_BOOLEAN;}
array {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_ARRAY;}
function {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_FUNCTION;}
if {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_IF;}
else {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_ELSE;}
while {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_WHILE;}
scanf {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_SCANF;}
printf {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_PRINTF;}
return {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_RETURN;}
";" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_PUNTOYCOMA;}
"," {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_COMA;}
"(" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_PARENTESISIZQUIERDO;}
")" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_PARENTESISDERECHO;}
"[" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_CORCHETEIZQUIERDO;}
"]" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_CORCHETEDERECHO;}
"{" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_LLAVEIZQUIERDA;}
"}" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_LLAVEDERECHA;}
"=" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_ASIGNACION;}
"+" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MAS;}
"-" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MENOS;}
"/" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_DIVISION;}
"*" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_ASTERISCO;}
"&&" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_AND;}
"||" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_OR;}
"!" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_NOT;}
"==" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_IGUAL;}
"!=" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_DISTINTO;}
"<=" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MENORIGUAL;}
">=" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MAYORIGUAL;}
"<" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MENOR;}
">" {col+=yyleng; strcpy(yylval.string,yytext);fprintf(yyout,";D:\t%s\n",yytext); return TOK_MAYOR;}
true {col+=yyleng; strcpy(yylval.string,yytext); fprintf(yyout,";D:\t%s\n",yytext); return TOK_TRUE;}
false {col+=yyleng; strcpy(yylval.string,yytext); fprintf(yyout,";D:\t%s\n",yytext); return TOK_FALSE;}
[a-zA-Z][a-zA-Z0-9]* {col+=yyleng; strcpy(yylval.string,yytext); if(yyleng<=100){fprintf(yyout,";D:\t%s\n",yytext);}else{fprintf(stdout,"****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",line,col-yyleng,yytext); error=1; return TOK_ERROR;}; return TOK_IDENTIFICADOR;}
[0-9]+ {col+=yyleng; yylval.num=atoi(yytext); fprintf(yyout,";D:\t%s\n",yytext); return TOK_CONSTANTE_ENTERA;}
. {error=1; col+=yyleng; strcpy(yylval.string,yytext); fprintf(stdout,"****Error morfologico en [lin %d, col %d]: simbolo no permitido (%s)\n",line,col-yyleng,yytext); return TOK_ERROR;}
%%
