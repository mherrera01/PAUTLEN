#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern char * yytext;
extern int yyleng;
extern int col;
extern int line;
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
		        fprintf(salida, "TOK_MAIN\t%d\t%s\n", TOK_MAIN, yytext);
		        break;
		    
		    case TOK_INT:
		        fprintf(salida, "TOK_INT\t%d\t%s\n", TOK_INT, yytext);
		        break;
		    
		    case TOK_BOOLEAN:
		        fprintf(salida, "TOK_BOOLEAN\t%d\t%s\n", TOK_BOOLEAN, yytext);
		        break;

		    case TOK_ARRAY:
		        fprintf(salida, "TOK_ARRAY\t%d\t%s\n", TOK_ARRAY, yytext);
		        break;

		    case TOK_FUNCTION:
		        fprintf(salida, "TOK_FUNCTION\t%d\t%s\n", TOK_FUNCTION, yytext);
		        break;

		    case TOK_IF:
		        fprintf(salida, "TOK_IF\t%d\t%s\n", TOK_IF, yytext);
		        break;

		    case TOK_ELSE:
		        fprintf(salida, "TOK_ELSE\t%d\t%s\n", TOK_ELSE, yytext);
		        break;

		    case TOK_WHILE:
		        fprintf(salida, "TOK_WHILE\t%d\t%s\n", TOK_WHILE, yytext);
		        break;
		    
		    case TOK_SCANF:
		        fprintf(salida, "TOK_SCANF\t%d\t%s\n", TOK_SCANF, yytext);
		        break;

		    case TOK_PRINTF:
		        fprintf(salida, "TOK_PRINTF\t%d\t%s\n", TOK_PRINTF, yytext);
		        break;

		    case TOK_RETURN:
		        fprintf(salida, "TOK_RETURN\t%d\t%s\n", TOK_RETURN, yytext);
		        break;

		    case TOK_PUNTOYCOMA:
		        fprintf(salida, "TOK_PUNTOYCOMA\t%d\t%s\n", TOK_PUNTOYCOMA, yytext);
		        break;

		    case TOK_COMA:
		        fprintf(salida, "TOK_COMA\t%d\t%s\n", TOK_COMA, yytext);
		        break;

		    case TOK_PARENTESISIZQUIERDO:
		        fprintf(salida, "TOK_PARENTESISIZQUIERDO\t%d\t%s\n", TOK_PARENTESISIZQUIERDO, yytext);
		        break;

		    case TOK_PARENTESISDERECHO:
		        fprintf(salida, "TOK_PARENTESISDERECHO\t%d\t%s\n", TOK_PARENTESISDERECHO, yytext);
		        break;

		    case TOK_CORCHETEIZQUIERDO:
		        fprintf(salida, "TOK_CORCHETEIZQUIERDO\t%d\t%s\n", TOK_CORCHETEIZQUIERDO, yytext);
		        break;

		    case TOK_CORCHETEDERECHO:
		        fprintf(salida, "TOK_CORCHETEDERECHO\t%d\t%s\n", TOK_CORCHETEDERECHO, yytext);
		        break;

		    case TOK_LLAVEIZQUIERDA:
		        fprintf(salida, "TOK_LLAVEIZQUIERDA\t%d\t%s\n", TOK_LLAVEIZQUIERDA, yytext);
		        break;

		    case TOK_LLAVEDERECHA:
		        fprintf(salida, "TOK_LLAVEDERECHA\t%d\t%s\n", TOK_LLAVEDERECHA, yytext);
		        break;

		    case TOK_ASIGNACION:
		        fprintf(salida, "TOK_ASIGNACION\t%d\t%s\n", TOK_ASIGNACION, yytext);
		        break;

		    case TOK_MAS:
		        fprintf(salida, "TOK_MAS\t%d\t%s\n", TOK_MAS, yytext);
		        break;

		    case TOK_MENOS:
		        fprintf(salida, "TOK_MENOS\t%d\t%s\n", TOK_MENOS, yytext);
		        break;

		    case TOK_DIVISION:
		        fprintf(salida, "TOK_DIVISION\t%d\t%s\n", TOK_DIVISION, yytext);
		        break;

		    case TOK_ASTERISCO:
		        fprintf(salida, "TOK_ASTERISCO\t%d\t%s\n", TOK_ASTERISCO, yytext);
		        break;

		    case TOK_AND:
		        fprintf(salida, "TOK_AND\t%d\t%s\n", TOK_AND, yytext);
		        break;

		    case TOK_OR:
		        fprintf(salida, "TOK_OR\t%d\t%s\n", TOK_OR, yytext);
		        break;

		    case TOK_NOT:
		        fprintf(salida, "TOK_NOT\t%d\t%s\n", TOK_NOT, yytext);
		        break;

		    case TOK_IGUAL:
		        fprintf(salida, "TOK_IGUAL\t%d\t%s\n", TOK_IGUAL, yytext);
		        break;

		    case TOK_DISTINTO:
		        fprintf(salida, "TOK_DISTINTO\t%d\t%s\n", TOK_DISTINTO, yytext);
		        break;

		    case TOK_MENORIGUAL:
		        fprintf(salida, "TOK_MENORIGUAL\t%d\t%s\n", TOK_MENORIGUAL, yytext);
		        break;

		    case TOK_MAYORIGUAL:
		        fprintf(salida, "TOK_MAYORIGUAL\t%d\t%s\n", TOK_MAYORIGUAL, yytext);
		        break;

		    case TOK_MENOR:
		        fprintf(salida, "TOK_MENOR\t%d\t%s\n", TOK_MENOR, yytext);
		        break;

		    case TOK_MAYOR:
		        fprintf(salida, "TOK_MAYOR\t%d\t%s\n", TOK_MAYOR, yytext);
		        break;

		    case TOK_IDENTIFICADOR:
		        if(yyleng <= 100){
		            fprintf(salida, "TOK_IDENTIFICADOR\t%d\t%s\n", TOK_IDENTIFICADOR, yytext);
		        }else{
		            fprintf(salida, "ERROR EN LINEA %d COLUMNA %d.\t RETURN TOK_ERROR %d\tIDENTIFICADOR DEMASIADO LARGO:%s\n",line, col-yyleng, TOK_ERROR, yytext);
		        }
		        break;

		    case TOK_CONSTANTE_ENTERA:
		        fprintf(salida, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", TOK_CONSTANTE_ENTERA, yytext);
		        break;

		    case TOK_TRUE:
		        fprintf(salida, "TOK_TRUE\t%d\t%s\n", TOK_TRUE, yytext);
		        break;

		    case TOK_FALSE:
		        fprintf(salida, "TOK_FALSE\t%d\t%s\n", TOK_FALSE, yytext);
		        break;

		    case TOK_ERROR:
		        fprintf(salida, "ERROR EN LINEA %d COLUMNA %d.\t RETURN TOK_ERROR %d\tSIMBOLO NO IDENTIFICADO:%s\n",line, col-yyleng, TOK_ERROR, yytext);
		        break;
		    
		    default:
		        break;


		}
	}

	fclose(salida);
	fclose(yyin);
	return 0;


}

