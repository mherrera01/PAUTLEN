%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
%}

%union{
	int entero;
	char * nombre;
}

%token <entero> TOK_CTE_ENTERA
%token <real> TOK_CTE_REAL
%token <nombre> ID

%left '+' '-'
%left '*' '/'

%type <entero> exp
%start input


%%
exp : exp '+' exp {$$=$1+$3;} | exp '-' exp {$$=$1-$3;} | exp '*' exp {$$=$1*$3;} | exp '/' exp {$$=$1/$3;} | '-' exp {$$=-$2;} | '(' exp ')' {$$=$2;} | constante;
constante : TOK_CTE_ENTERA | TOK_CTE_REAL;

%%

int yyerror(char *s) { printf("%s\n",s); }
int main(void) { yyparse(); }