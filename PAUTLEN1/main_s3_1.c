#include <stdio.h>
#include "generacion.h"

int main (int argc, char ** argv)
{
	FILE * salida;

	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}
	

	salida = fopen(argv[1],"w");


	escribir_subseccion_data(salida);
	escribir_cabecera_bss(salida);


	escribir_segmento_codigo(salida);
	
	declararFuncion(salida, "dos", 0);
	escribir_operando(salida,"2",0);
	escribir(salida,0,ENTERO);
	escribir_operando(salida,"2",0);
	retornarFuncion(salida,0);
	
	escribir_inicio_main(salida);

	llamarFuncion(salida,"dos",0);
	escribir(salida,0,ENTERO);



	escribir_fin(salida);

	fclose(salida);
	return 0;


}
