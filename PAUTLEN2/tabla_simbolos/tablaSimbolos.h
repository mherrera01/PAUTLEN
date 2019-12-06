#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "tablaHash.h"

STATUS DeclararGlobal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

STATUS DeclararLocal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

entry_t * UsoGlobal(char * identificador);

entry_t * UsoLocal(char * identificador);

STATUS DeclararFuncion(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2);

void CerrarFuncion();

void LimpiarTablas();

void ImprimirTablaGlobal();

void ImprimirTablaLocal();

#endif