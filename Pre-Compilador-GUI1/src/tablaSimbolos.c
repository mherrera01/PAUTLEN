#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tablaSimbolos.h"


TABLA_HASH * tablaSimbolosLocal = NULL;
TABLA_HASH * tablaSimbolosGlobal = NULL;

TABLA_HASH * CrearTablaGlobal(){
    if(tablaSimbolosGlobal == NULL){
       tablaSimbolosGlobal = crear_tabla(TAM_GLOBAL);
       return tablaSimbolosGlobal;
    }

    return NULL;
}

TABLA_HASH * CrearTablaLocal(){
    if(tablaSimbolosLocal == NULL){
       tablaSimbolosLocal = crear_tabla(TAM_LOCAL);
       return tablaSimbolosLocal;
    }
    return NULL;
}



STATUS DeclararGlobal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    /*Esta creada, NO ==> CREAR TABLA GLOBAL E INSERTAR*/
    if(tablaSimbolosGlobal == NULL){
        tablaSimbolosGlobal = CrearTablaGlobal();
        return insertar_simbolo(tablaSimbolosGlobal,identificador, categoria,tipo, clase, valor1, valor2);
    }else{
        return insertar_simbolo(tablaSimbolosGlobal,identificador, categoria,tipo, clase, valor1, valor2);
    }
}

STATUS DeclararLocal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    /*Esta creada, NO ==> CREAR TABLA LOCAL E INSERTAR*/
    if(tablaSimbolosLocal == NULL){
        tablaSimbolosLocal = CrearTablaLocal();
        return insertar_simbolo(tablaSimbolosLocal,identificador, categoria,tipo, clase, valor1, valor2);
    }else{
        return insertar_simbolo(tablaSimbolosLocal,identificador, categoria,tipo, clase, valor1, valor2);
    }
}

INFO_SIMBOLO * UsoGlobal(char * identificador){

     /*Esta creada ==> retornar el elemento global*/
    if(tablaSimbolosGlobal != NULL){
        return buscar_simbolo(tablaSimbolosGlobal, identificador);
    }else{ //TODAVIA no hay tabla creada
        return NULL;
    }

}

INFO_SIMBOLO * UsoLocal(char * identificador){

    INFO_SIMBOLO * aux=NULL;
    /*Esta creada ==> retornar el elemento local*/
    if(tablaSimbolosLocal != NULL){
        aux = buscar_simbolo(tablaSimbolosLocal, identificador);
        if(aux != NULL){
            return aux;
        }
    }

    return UsoGlobal(identificador);
}

INFO_SIMBOLO * UsoExclusivoGlobal(char * identificador){
    if(tablaSimbolosGlobal != NULL){
        return buscar_simbolo(tablaSimbolosGlobal, identificador);
    }else{ //TODAVIA no hay tabla creada
        return NULL;
    }
}

INFO_SIMBOLO * UsoExclusivoLocal(char * identificador){
    if(tablaSimbolosLocal != NULL){
        return buscar_simbolo(tablaSimbolosLocal, identificador);
    }else{ //TODAVIA no hay tabla creada
        return NULL;
    }
}


STATUS DeclararFuncion(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    if (tablaSimbolosGlobal == NULL) {
        tablaSimbolosGlobal = crear_tabla(TAM_GLOBAL);
        if (tablaSimbolosGlobal == NULL)
            return ERROR;
        insertar_simbolo(tablaSimbolosGlobal,identificador,categoria,tipo,clase,valor1,valor2);
    }else{
        insertar_simbolo(tablaSimbolosGlobal,identificador,categoria,tipo,clase,valor1,valor2);
    }

    if(tablaSimbolosLocal != NULL){
        liberar_tabla(tablaSimbolosLocal);
    }

    tablaSimbolosLocal = CrearTablaLocal();

    if (tablaSimbolosLocal != NULL) {
        return insertar_simbolo(tablaSimbolosLocal,identificador,categoria,tipo,clase, valor1,valor2);

    } else {
        return ERROR;
    }
}

void CerrarFuncion(){
    if(tablaSimbolosLocal != NULL){
        liberar_tabla(tablaSimbolosLocal);
        tablaSimbolosLocal = NULL;
    }
}

void LimpiarTablas(){
    CerrarFuncion();
    liberar_tabla(tablaSimbolosGlobal);
    tablaSimbolosGlobal = NULL;
}

void ImprimirTablaGlobal(){
    tabla_dump(tablaSimbolosGlobal);
}

void ImprimirTablaLocal(){
    tabla_dump(tablaSimbolosLocal);
}
