#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "tablaHash.h"

#define TAM_GLOBAL 100
#define TAM_LOCAL 100

TABLA_HASH * CrearTablaGlobal();

TABLA_HASH * CrearTablaLocal();

STATUS DeclararGlobal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

STATUS DeclararLocal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

INFO_SIMBOLO * UsoGlobal(char * identificador);

INFO_SIMBOLO * UsoLocal(char * identificador);

INFO_SIMBOLO * UsoExclusivoGlobal(char * identificador);

INFO_SIMBOLO * UsoExclusivoLocal(char * identificador);

STATUS DeclararFuncion(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

void CerrarFuncion();

void LimpiarTablas();

void ImprimirTablaGlobal();

void ImprimirTablaLocal();

#endif
