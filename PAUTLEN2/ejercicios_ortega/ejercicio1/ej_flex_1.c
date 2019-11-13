#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern char * yytext;
FILE * salida;

int main(int argc, char** argv){

	int valor_patron=0;

	if(argc < 3){
		printf("Error en los parametros ==>> ./ejecutable fichero_entrada fichero_salida");
		return -1;
	}

	yyin = fopen(argv[1], "r");
	salida = fopen(argv[2],"w+");

	while((valor_patron = yylex()) != 0){

		switch(valor_patron){
			
			case TOK_MAIN:
				fprintf(salida,"TOK_MAIN %d %s\n", valor_patron, yytext);
				break;

			case TOK_INT:
				fprintf(salida,"TOK_INT %d %s\n", valor_patron, yytext);
				break;

			case TOK_ARRAY:
				fprintf(salida,"TOK_ARRAY %d %s\n", valor_patron, yytext);
				break;

			case TOK_IF:
				fprintf(salida,"TOK_IF %d %s\n", valor_patron, yytext);
				break;
	
			case TOK_ELSE:
				fprintf(salida,"TOK_ELSE %d %s\n", valor_patron, yytext);
				break;

			case TOK_WHILE:
				fprintf(salida,"TOK_WHILE %d %s\n", valor_patron, yytext);
				break;
			default:
				printf("\nError producido detectando una expresion");

		}
	}

	fclose(salida);
	fclose(yyin);
	return 0;


}
