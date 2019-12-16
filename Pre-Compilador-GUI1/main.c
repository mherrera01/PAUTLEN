#include <stdio.h>
#include "alfa.h"
#include "y.tab.h"
#include "tablaHash.h"


extern FILE *yyin, *yyout;
extern int yyparse();

int main(int argc, char** argv){
	
    if (argc != 3) {
		fprintf (stdout, "Error en los argumentos de entrada, asegurese que es de la forma:\n ./main <fichero_entrada> <fichero_salida>\n"); 
		return -1;
	}
    
    yyin = fopen(argv[1],"r");

    if(!yyin){
    	fprintf(stdout, "Error al abrir el fichero de lectura\n");
    	return -1;
    }

    yyout=fopen(argv[2],"w");
    
    if(!yyout){
    	fprintf(stdout, "Error al abrir el fichero de salida\n");
    	return -1;
    }

    yyparse();

    fclose(yyout);
    fclose(yyin);

    return 0;

}