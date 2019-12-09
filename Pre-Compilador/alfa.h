#ifndef _ALFA_H
#define _ALFA_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tablaSimbolos.h"

#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

typedef struct{
	char lexema[MAX_LONG_ID+1]; /*nombre(lexema) de identificadores*/
	int valor_entero; /*valor de constante entera*/
	TIPO tipo; /*tipo entero o booleano de variable*/
	int direcciones; /*direccion si es que tiene que guardar una direccion*/
    int etiqueta; /*atributo para los casos de sentencias condicionales e iterativas*/
}tipo_atributos;


#endif