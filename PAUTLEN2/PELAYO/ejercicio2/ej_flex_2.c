#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern char yytext[];
FILE * yyout;

int main(int argc, char** argv){

	int valor_patron=0;

	if(argc < 3){
		printf("Error en los parametros ==>> ./ejecutable fichero_entrada fichero_salida");
		return -1;
	}

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2],"w+");

	while((valor_patron = yylex()) != 0){

		switch(valor_patron){
			
			case TOK_MAIN:
				fprintf(yyout,"TOK_MAIN %d %s", valor_patron, yytext);
				break;

			case TOK_INT:
				fprintf(yyout,"TOK_INT %d %s", valor_patron, yytext);
				break;

			case TOK_ARRAY:
				fprintf(yyout,"TOK_ARRAY %d %s", valor_patron, yytext);
				break;

			case TOK_IF:
				fprintf(yyout,"TOK_IF %d %s", valor_patron, yytext);
				break;
	
			case TOK_ELSE:
				fprintf(yyout,"TOK_ELSE %d %s", valor_patron, yytext);
				break;

			case TOK_WHILE:
				fprintf(yyout,"TOK_WHILE %d %s", valor_patron, yytext);
				break;

			case TOK_PUNTOYCOMA:
				fprintf(yyout,"TOK_PUNTOYCOMA %d %s", valor_patron, yytext);
				break;

			case TOK_PARENTESISIZQUIERDO:
				fprintf(yyout,"TOK_PARENTESISIZQUIERDO %d %s", valor_patron, yytext);
				break;

			case TOK_PARENTESISDERECHO:
				fprintf(yyout,"TOK_PARENTESISDERECHO %d %s", valor_patron, yytext);
				break;

			case TOK_ASTERISCO:
				fprintf(yyout,"TOK_ASTERISCO %d %s", valor_patron, yytext);
				break;

			case TOK_MAS:
				fprintf(yyout,"TOK_MAS %d %s", valor_patron, yytext);
				break;

			case TOK_MENORIGUAL:
				fprintf(yyout,"TOK_MENORIGUAL %d %s", valor_patron, yytext);
				break;

			default:
				printf("\nError producido detectando una expresion");

		}
	}

	fclose(yyout);
	fclose(yyin);
	return 0;


}
