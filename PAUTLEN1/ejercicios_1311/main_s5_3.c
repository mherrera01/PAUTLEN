#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generacion.h"

int main (int argc, char ** argv)
{

    	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

    	int etiqueta = 0;
    	int getiqueta = 0;
    	int etiquetas[MAX_ETIQUETAS];
    	int cima_etiquetas=-1;
    	FILE * fd_asm;

    	fd_asm = fopen(argv[1],"w");
    	escribir_subseccion_data(fd_asm);
    	escribir_cabecera_bss(fd_asm);

    	//int m;
    	declarar_variable(fd_asm,"m", 1, 1);

        //int x;
        declarar_variable(fd_asm,"x", 1, 1);

    	//int [4] v;
    	declarar_variable(fd_asm, "v",  1, 4);

        //bool [4] vb;
        declarar_variable(fd_asm, "vb",  1, 4);

        //int doble_cota;
        declarar_variable(fd_asm, "doble_cota",  1, 1);

    	escribir_segmento_codigo(fd_asm);

        //funcion factorial
        declararFuncion(fasm, "factorial", 0);

        escribirParametro(fasm,0,1);
        operandoEnPilaAArgumento(fasm, 1);
        escribir_operando(fasm,"0",0);
        igual(fasm,1,0,etiqueta);

        ifthenelse_inicio(fasm, 0, etiqueta); //PRIMER IF THEN ELSE

        //RETORNO 1
        escribir_operando(salida,"1",0);
        retornarFuncion(salida,0);

        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin_then(fasm, etiqueta);

        //RETORNO N * FACTORIAL(N-1);


        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin(fasm, etiqueta);
        cima_etiquetas--;


        //funcion grande
        declararFuncion(fasm, "factorial", 1);



        //escribirParametro(fasm,0,2);
        //operandoEnPilaAArgumento(fasm, 1);

        escribirParametro(fasm,1,2);
        operandoEnPilaAArgumento(fasm, 1);

        escribir_operando(fasm,"2",0);

        multiplicar(fasm,);



        escribir_operando(fasm,"0",0);

        igual(fasm,1,0,etiqueta);

        ifthenelse_inicio(fasm, 0, etiqueta); //PRIMER IF THEN ELSE

        //RETORNO 1
        escribir_operando(salida,"1",0);
        retornarFuncion(salida,0);

        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin_then(fasm, etiqueta);

        //RETORNO N * FACTORIAL(N-1);


        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin(fasm, etiqueta);
        cima_etiquetas--;

        retornarFuncion(fasm, 0);




    	escribir_inicio_main(fd_asm);

        

    	//m=0;
    	escribir_operando(fd_asm,"0",0);
    	asignar(fd_asm,"m",0);


       //While. Gestion inicial de las etiquetas, guardado de etiqueta.
    	getiqueta++;
    	cima_etiquetas++;
    	etiquetas[cima_etiquetas]=getiqueta;

    	//Inicio del while. Impresion de la etiqueta.
    	etiqueta = etiquetas[cima_etiquetas];
    	while_inicio(fd_asm, etiqueta);

    	//Condicion del bucle while.
    	escribir_operando(fd_asm,"m",1);
    	escribir_operando(fd_asm,"4",0);
    	menor(fd_asm,1,0,etiqueta);

    	//Recuperamos la etiqueta para imprimir la comparacion del while.
    	etiqueta = etiquetas[cima_etiquetas];
    	while_exp_pila(fd_asm, 0, etiqueta);

    	//printf m
    	escribir_operando(fd_asm,"m",1);
    	escribir(fd_asm,1,ENTERO);

         //v[m] = m*10;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"10",0);
        multiplicar(fd_asm,1,0);


        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"v", 4, 1);
        asignarDestinoEnPila(fd_asm,0);

    	//v[m] = !(m > 2);
    	escribir_operando(fd_asm,"m",1);
    	escribir_operando(fd_asm,"2",0);
    	mayor(fd_asm,1,0,etiqueta);

    
        no(fd_asm,0,etiqueta);
        escribir_operando(fd_asm, "m", 1);
    	escribir_elemento_vector(fd_asm,"vb", 4, 1);
        asignarDestinoEnPila(fd_asm, 0); 

       //m = m + 1
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"1",0);
        sumar(fd_asm,1,0);
        asignar(fd_asm,"m",0);

        //Recuperamos la etiqueta para imprimir el fin de etiqueta del while.
        etiqueta = etiquetas[cima_etiquetas];
        while_fin(fd_asm, etiqueta);

        //Al cerrar el ámbito, decrementamos el contador de cima de etiquetas.
        cima_etiquetas--;

        //m=0;
        escribir_operando(fd_asm,"0",0);
        asignar(fd_asm,"m",0);

        //WHILE 2
        getiqueta++;
        cima_etiquetas++;
        etiquetas[cima_etiquetas]=getiqueta;

        //Inicio del while. Impresion de la etiqueta.
        etiqueta = etiquetas[cima_etiquetas];
        while_inicio(fd_asm, etiqueta);


        //Condicion del bucle while.
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"4",0);
        menor(fd_asm,1,0,etiqueta);

        //Recuperamos la etiqueta para imprimir la comparacion del while.
        etiqueta = etiquetas[cima_etiquetas];
        while_exp_pila(fd_asm, 0, etiqueta);

        escribir_operando(fd_asm, "m", 1);
        escribir_elemento_vector(fd_asm,"v", 4, 1);
        escribir(fd_asm,1,ENTERO);

        escribir_operando(fd_asm, "m", 1);
        escribir_elemento_vector(fd_asm,"vb", 4, 1);
        escribir(fd_asm,1,BOOLEANO);

        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"1",0);
        sumar(fd_asm,1,0);
        asignar(fd_asm,"m",0);

        //Recuperamos la etiqueta para imprimir el fin de etiqueta del while.
        etiqueta = etiquetas[cima_etiquetas];
        while_fin(fd_asm, etiqueta);

        //Al cerrar el ámbito, decrementamos el contador de cima de etiquetas.
        cima_etiquetas--;

        escribir_fin(fd_asm);

        fclose(fd_asm);
}
