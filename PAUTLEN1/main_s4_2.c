#include <stdio.h>
#include "generacion.h"

int main(int argc, char** argv){
    FILE *fasm;
    int etiqueta = 0;
    int getiqueta = 0;
    int etiquetas[MAX_ETIQUETAS];
    int cima_etiquetas=-1;
    if(argc != 2){
        fprintf(stderr, "ERROR AL INTRODUCIR EL NUMERO DE ARGUMENTOS. INTRODUZCA EL NOMBRE DEL FICHERO DE SALIDA.\n");
        return -1;
    }



    fasm = fopen(argv[1], "w");

    escribir_subseccion_data(fasm);
    escribir_cabecera_bss(fasm);
    declarar_variable(fasm, "m", ENTERO, 1);
    declarar_variable(fasm, "b1", BOOLEANO, 1);
    escribir_segmento_codigo(fasm);

    escribir_inicio_main(fasm);

    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;

    leer(fasm, "m", ENTERO);
    
    escribir_operando(fasm, "m", 1);
    escribir_operando(fasm,"5",0);
    
    mayor(fasm,1,0,etiqueta);

    escribir_operando(fasm,"b1",1);
    asignarDestinoEnPila(fasm, 0);   

    escribir_operando(fasm,"b1",1);
    escribir_operando(fasm,"0",0);


    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;
    distinto(fasm,1,0,etiqueta);

    ifthenelse_inicio(fasm, 0, etiqueta); //PRIMER IF THEN ELSE

    escribir_operando(fasm,"2",0);
    escribir(fasm, 0, ENTERO);

    //ESCRIBIR THEN ELSE E IMPRIMIR
    etiqueta = etiquetas[cima_etiquetas];
    ifthenelse_fin_then(fasm, etiqueta);

    escribir_operando(fasm,"3",0);
    escribir(fasm, 0, ENTERO);

    etiqueta = etiquetas[cima_etiquetas];
    ifthenelse_fin(fasm, etiqueta);
    cima_etiquetas--;


    escribir_fin(fasm);
    fclose(fasm);

    return 0;
    
}
