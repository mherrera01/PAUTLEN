#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"


ht_t * tablaSimbolosLocal = NULL;
ht_t * tablaSimbolosGlobal = NULL;

STATUS DeclararGlobal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    /*Esta creada, NO ==> CREAR TABLA GLOBAL E INSERTAR*/
    if(tablaSimbolosGlobal == NULL){
        tablaSimbolosGlobal = ht_create();
        return ht_set(tablaSimbolosGlobal,identificador, categoria,tipo, clase, valor1, valor2);
    }else{
        return ht_set(tablaSimbolosGlobal,identificador, categoria,tipo, clase, valor1, valor2);
    }
}

STATUS DeclararLocal(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    /*Esta creada, NO ==> CREAR TABLA LOCAL E INSERTAR*/
    if(tablaSimbolosLocal == NULL){
        tablaSimbolosLocal = ht_create();
        return ht_set(tablaSimbolosLocal,identificador, categoria,tipo, clase, valor1, valor2);
    }else{
        return ht_set(tablaSimbolosLocal,identificador, categoria,tipo, clase, valor1, valor2);
    }
}

entry_t * UsoGlobal(char * identificador){

     /*Esta creada ==> retornar el elemento global*/
    if(tablaSimbolosGlobal != NULL){
        return ht_get(tablaSimbolosGlobal, identificador);
    }else{ //TODAVIA no hay tabla creada
        return NULL;
    }
    
}

entry_t * UsoLocal(char * identificador){

    /*Esta creada ==> retornar el elemento local*/
    if(tablaSimbolosLocal != NULL){
        return ht_get(tablaSimbolosLocal, identificador);
    }else{ //TODAVIA no hay tabla creada
        return NULL;
    }
}

STATUS DeclararFuncion(char * identificador,CATEGORIA categoria, TIPO tipo, CLASE clase, int valor1, int valor2){

    if (tablaSimbolosGlobal == NULL) {
        tablaSimbolosGlobal = ht_create();
        if (tablaSimbolosGlobal == NULL)
            return ERROR;
        ht_set(tablaSimbolosGlobal,identificador,categoria,tipo,clase,valor1,valor2);
    }else{
        ht_set(tablaSimbolosGlobal,identificador,categoria,tipo,clase,valor1,valor2);
    }

    if(tablaSimbolosLocal != NULL){
        ht_destroy(tablaSimbolosLocal);
    }

    tablaSimbolosLocal = ht_create();
    
    if (tablaSimbolosLocal != NULL) {
        return ht_set(tablaSimbolosLocal,identificador,categoria,tipo,clase, valor1,valor2);
    } else {
        return ERROR;
    }    
}

void CerrarFuncion(){
    if(tablaSimbolosLocal != NULL){
        ht_destroy(tablaSimbolosLocal);
        tablaSimbolosLocal = NULL;
    }
}

void LimpiarTablas(){
    CerrarFuncion();
    ht_destroy(tablaSimbolosGlobal);
    tablaSimbolosGlobal = NULL;
}

void ImprimirTablaGlobal(){
    ht_dump(tablaSimbolosGlobal);
}

void ImprimirTablaLocal(){
    ht_dump(tablaSimbolosLocal);
}