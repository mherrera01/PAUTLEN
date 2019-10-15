#include <stdio.h>
#include "generacion.h"

int main (int argc, char ** argv)
{
/*
	int x;

	scanf x;
	printf x;
*/
	FILE * salida;

	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}
	

	salida = fopen(argv[1],"w");


	escribir_subseccion_data(salida);
	escribir_cabecera_bss(salida);


	declarar_variable(salida, "x", ENTERO, 1);


	escribir_segmento_codigo(salida);
	escribir_inicio_main(salida);

	/* scanf x; */

	leer(salida,"x",ENTERO);


	/* printf x; */

	escribir_operando(salida,"x",1);
	escribir(salida,1,ENTERO);



	escribir_fin(salida);

	fclose(salida);
	return 0;


}
