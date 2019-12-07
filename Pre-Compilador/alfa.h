#ifndef _ALFA_H
#define _ALFA_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


#define MAX_LONG_ID 100

typedef struct
{
	char lexema[MAX_LONG_ID+1];
	int valor_entero;
	int tipo;
	int direcciones;
    int etiqueta;
}tipo_atributos;


#endif