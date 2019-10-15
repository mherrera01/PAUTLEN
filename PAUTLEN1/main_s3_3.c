#include <stdio.h>
#include "generacion.h"

int main(int argc, char** argv){
    FILE *fasm;

    if(argc != 2){
        fprintf(stderr, "ERROR AL INTRODUCIR EL NUMERO DE ARGUMENTOS. INTRODUZCA EL NOMBRE DEL FICHERO DE SALIDA.\n");
        return -1;
    }

    fasm = fopen(argv[1], "w");

    escribir_subseccion_data(fasm);
	
    escribir_cabecera_bss(fasm);
    declarar_variable(fasm, "x", ENTERO, 1);

    escribir_segmento_codigo(fasm);

    declararFuncion(fasm, "doble", 1);
	escribirParametro(fasm,0,1);
	operandoEnPilaAArgumento(fasm, 1);
    escribir(fasm, 0, ENTERO);
	
	escribirParametro(fasm,0,1);
    escribir_operando(fasm, "2", 0);
    multiplicar(fasm, 1, 0);
	
    retornarFuncion(fasm, 0);

    escribir_inicio_main(fasm);

    leer(fasm, "x", ENTERO);
    escribir_operando(fasm, "x", 1);
    operandoEnPilaAArgumento(fasm, 1);
    llamarFuncion(fasm, "doble", 0);
    escribir(fasm, 0, ENTERO);
    escribir_fin(fasm);
    fclose(fasm);

    return 0;
    
}
