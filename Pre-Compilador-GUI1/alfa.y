%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "alfa.h"

    void yyerror(const char* err);
    extern int line, col, error;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int yylex();
    extern int yyleng;

    /*variables para conocer el estado actual del simbolo*/
    TIPO tipo_actual;
    CLASE clase_actual;
    INFO_SIMBOLO * aux;
    int tamanio_vector_actual=0; //Tamanio del vector
    int pos_variable_local_actual=1; //Posicion de variable global en ambitos de variables locales


    /*Ambito global y local*/
    extern TABLA_HASH * tablaSimbolosLocal;
    extern TABLA_HASH * tablaSimbolosGlobal;

    /*Otra informacion*/
    int num_variables_locales_actual=0;
    int cuantos_no=0;
    char aux_char[100];
    int en_explist=0;
    int etiqueta=1;

    /*Parametros*/
    int num_parametros_actual=0;
    int pos_parametro_actual=0;
    int num_parametros_llamada_actual=0;
    int comprobacion_parametros=0;

    /*Etiquetas*/
    int num_comparaciones=0;

    /*Funciones*/
    int fn_return=0;
    int tipo_retorno=0;

%}
%union
        {
            tipo_atributos atributos;
        }


/*Simbolos no terminales con valor semantico*/

%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador
%type <atributos> fn_declaracion
%type <atributos> fn_name
%type <atributos> if_exp
%type <atributos> if_exp_sentencias
%type <atributos> bucle_exp
%type <atributos> bucle_exp_sentencias

/*Simbolos terminales con valor semantico*/

%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_CONSTANTE_REAL
%token <atributos> TOK_IDENTIFICADOR

/*Simbolos terminales sin valor semantico*/

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

%left TOK_ASIGNACION
%left TOK_AND TOK_OR
%left TOK_IGUAL TOK_DISTINTO
%left TOK_MAYOR TOK_MENOR TOK_MAYORIGUAL TOK_MENORIGUAL
%left TOK_MAS TOK_MENOS
%left TOK_DIVISION TOK_ASTERISCO
%right TOK_NOT MENOSU
%left TOK_PARENTESISIZQUIERDO TOK_PARENTESISDERECHO TOK_CORCHETEIZQUIERDO TOK_CORCHETEDERECHO

%start programa

%%
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 1
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
programa: TOK_MAIN TOK_LLAVEIZQUIERDA inicio declaraciones escritura1 funciones escritura2 sentencias fin TOK_LLAVEDERECHA {
    fprintf(stdout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
}
;

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  INICIO DE TABLA GLOBAL Y ESCRITURA DE SECCIONES DATA Y BSS
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
inicio:{
    CrearTablaGlobal();
    escribir_subseccion_data(yyout);
    escribir_cabecera_bss(yyout);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  LIBERACION DE TABLAS Y ESCRITURA DE SECCION FINAL
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
fin:{
    escribir_fin(yyout);
    LimpiarTablas();
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  ESCRITURA DEL SEGMENTO DE CODIGO
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
escritura1:{
    INFO_SIMBOLO * totales = tablaSimbolosGlobal->simbolos;
    while(totales != NULL){

        if(totales->categoria == VARIABLE){
            if(totales->tipo == INT) {
                declarar_variable(yyout,totales->lexema,ENTERO,(totales->clase == VECTOR) ? totales->adicional1 : 1);
            }else if(totales->tipo == BOOLEAN){
                declarar_variable(yyout,totales->lexema,BOOLEANO,(totales->clase == VECTOR) ? totales->adicional1 : 1);
            }
        }

        totales = totales->siguiente;
    }

    escribir_segmento_codigo(yyout);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  ESCRITURA DE MAIN
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
escritura2:{
    escribir_inicio_main(yyout);
}

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 2
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
declaraciones: declaracion {

    fprintf(stdout, ";R2:\t<declaraciones> ::= <declaracion>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 3
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
            | declaracion declaraciones {

    fprintf(stdout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
};


/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 4
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
declaracion: clase identificadores TOK_PUNTOYCOMA {

    fprintf(stdout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 5
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
clase: clase_escalar {
    fprintf(stdout, ";R5:\t<clase> ::= <clase_escalar>\n");
    clase_actual=ESCALAR;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 7
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | clase_vector {
    fprintf(stdout, ";R7:\t<clase> ::= <clase_vector>\n");
    clase_actual=VECTOR;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 9
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
clase_escalar: tipo {
    fprintf(stdout, ";R9:\t<clase_escalar> ::= <tipo>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 10
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
tipo: TOK_INT {
    fprintf(stdout, ";R10:\t<tipo> ::= int\n");
    tipo_actual=INT;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 11
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_BOOLEAN {
    fprintf(stdout, ";R11:\t<tipo> ::= boolean\n");
    tipo_actual=BOOLEAN;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 15
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
    fprintf(stdout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
    tamanio_vector_actual = $4.valor_entero;
    if((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
        fprintf(stdout,"****Error Semantico en la linea %d: El tamanyo del vector excede los limites permitidos (1,64).\n", line);
        return -1;
    }
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 18
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
identificadores: identificador {
    fprintf(stdout, ";R18:\t<identificadores> ::= <identificador>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 19
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | identificador TOK_COMA identificadores {
    fprintf(stdout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 20
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
funciones: funcion funciones {
    fprintf(stdout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 21
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";R21:\t<funciones> ::=\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - FN_NAME
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
fn_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR {

    aux = UsoGlobal($3.lexema);

    if(aux != NULL){ //Error porque el identificador ya existe en este ambito
        fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada %s.\n", line, $3.lexema);
        return -1;
    }else{

        if(DeclararFuncion($3.lexema,FUNCION,tipo_actual,ESCALAR,-1,-1) == OK){
            pos_variable_local_actual=1;
            num_variables_locales_actual=0;
            pos_parametro_actual=0;
            num_parametros_actual=0;
            tamanio_vector_actual=0;
            $$.tipo = tipo_actual;
            strcpy($$.lexema,$3.lexema);
            fn_return = 0;
        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Fallo al declarar funcion (%s).\n",line,$3.lexema);
            return -1;
        }

    }
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - FN_DECLARACION
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
fn_declaracion: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion{

    aux = UsoExclusivoLocal($1.lexema);

    aux->adicional1 = num_parametros_actual;
    aux->adicional2 = num_variables_locales_actual;

    aux = UsoGlobal($1.lexema);

    aux->adicional1 = num_parametros_actual;
    aux->adicional2 = num_variables_locales_actual;

    $$ = $1;

    declararFuncion(yyout,$1.lexema,num_variables_locales_actual);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 22
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
funcion: fn_declaracion sentencias TOK_LLAVEDERECHA {
    fprintf(stdout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");

    CerrarFuncion();
    tablaSimbolosLocal=NULL;

    aux = UsoGlobal($1.lexema);

    if(aux == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d:  Acceso a variable no declarada (%s).\n", line, $1.lexema);
        return -1;
    }

    if(fn_return == 0){
        fprintf(stdout,"****Error Semantico en la linea %d:  Funcion %s sin sentencia de retorno.\n", line, $1.lexema);
        return -1;
    }

    if(tipo_retorno != aux->tipo){
      fprintf(stdout,"****Error Semantico en la linea %d: Retorno funcion %s tipo incorrecto.\n", line, $1.lexema);
      return -1;
    }

};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 23
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
parametros_funcion: parametro_funcion resto_parametros_funcion {
    fprintf(stdout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 24
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";;R24:\t<parametros_funcion> ::=\n");
};


/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 25
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
    fprintf(stdout, ";R25:\t <resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 26
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";R26:\t<resto_parametros_funcion> ::=\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 27
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
parametro_funcion: tipo idpf {
    fprintf(stdout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 28
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
declaraciones_funcion: declaraciones {
    fprintf(stdout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 29
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";R29:\t<declaraciones_funcion> ::=\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 30
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
sentencias: sentencia {
    fprintf(stdout, ";R30:\t<sentencias> ::= <sentencia>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 31
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | sentencia sentencias {
    fprintf(stdout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 32
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
sentencia: sentencia_simple TOK_PUNTOYCOMA {
    fprintf(stdout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 33
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | bloque {
    fprintf(stdout, ";R33:\t<sentencia> ::= <bloque>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 34
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
sentencia_simple: asignacion {
    fprintf(stdout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 35
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | lectura {
    fprintf(stdout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 36
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | escritura {
    fprintf(stdout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 38
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | retorno_funcion {
    fprintf(stdout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 40
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
bloque: condicional {
    fprintf(stdout, ";R40:\t<bloque> ::= <condicional>\n");
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 41
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | bucle {
    fprintf(stdout, ";R41:\t<bloque> ::= <bucle>\n");
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 43
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp {
    fprintf(stdout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    aux = UsoLocal($1.lexema);

    if(aux == NULL){ fprintf(stdout,"Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line,$1.lexema);
    return -1;}
    if(aux->categoria == FUNCION){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}
    if(aux->clase == VECTOR){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}
    if(aux->tipo != $3.tipo){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}

    /*quiere decir que es global*/
    if(UsoExclusivoLocal($1.lexema) == NULL){
        asignar(yyout,$1.lexema,$3.direcciones);

    /*quiere decir que es parametro*/
    }else if(aux->categoria == PARAMETRO){
        escribirParametro(yyout,aux->adicional2,num_parametros_actual);
        invertirEnPila(yyout);
        asignarDestinoEnPila(yyout,$3.direcciones);

    /*quiere decir que es local*/
    }else{
        escribirVariableLocal(yyout,aux->adicional2);
        invertirEnPila(yyout);
        asignarDestinoEnPila(yyout,$3.direcciones);
    }

}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 44
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | elemento_vector TOK_ASIGNACION exp {
        fprintf(stdout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
        aux = UsoLocal($1.lexema);

        if(aux == NULL){
            fprintf(stdout,"Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line, $1.lexema);
            return -1;}
        if(aux->tipo != $3.tipo){
            fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
            return -1;
        }

        asignarDestinoEnPila(yyout,$3.direcciones); /*o es una constante o es una variable*/
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 48
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {

    fprintf(stdout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
    aux = UsoGlobal($1.lexema);

    if(aux == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line, $1.lexema);
        return -1;
    }

    if(aux->clase != VECTOR){
        fprintf(stdout,"****Error Semantico en la linea %d: Intento de indexacion de una variable que no es de tipo vector.\n",line);
        return -1;
    }

    if($3.valor_entero > aux->adicional1){
        fprintf(stdout,"****Error Semantico en la linea %d: Posicion incorrecta para la indexacion del vector.\n",line);
        return -1;
    }

    if($3.tipo != INT){
        fprintf(stdout,"****Error Semantico en la linea %d:  El indice en una operacion de indexacion tiene que ser de tipo entero.\n",line);
        return -1;
    }

    if (en_explist == 0) {
      escribir_elemento_vector(yyout,$1.lexema,MAX_TAMANIO_VECTOR,$3.direcciones);
    }else{
      escribir_elemento_vector(yyout,$1.lexema,MAX_TAMANIO_VECTOR,$3.direcciones);
      operandoEnPilaAArgumento(yyout,1);
    }

    $$.tipo = aux->tipo;
    $$.direcciones = 1;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 50
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
condicional: if_exp_sentencias TOK_LLAVEDERECHA {
    fprintf(stdout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
    ifthenelse_fin(yyout, $1.etiqueta);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 51
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
    fprintf(stdout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
    ifthenelse_fin(yyout, $1.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - IF_EXP_SENTENCIAS
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
if_exp_sentencias: if_exp sentencias {

    $$.etiqueta = $1.etiqueta;
    ifthenelse_fin_then(yyout, $$.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - IF_EXP
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {

    if($3.tipo != BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Condicional con condicion de tipo int.\n",line);
        return -1;
    }

    $$.etiqueta = etiqueta++;
    ifthen_inicio(yyout, $3.direcciones, $$.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 52
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
bucle:  bucle_exp_sentencias  sentencias TOK_LLAVEDERECHA {
    fprintf(stdout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
    while_fin(yyout,$1.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - BUCLE_EXP_SENTENCIAS
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
bucle_exp_sentencias: bucle_exp TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {

    if($3.tipo != BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Bucle con condicion de tipo int.\n",line);
        return -1;
    }

    $$.direcciones = $3.direcciones;
    $$.etiqueta = $1.etiqueta;
    while_exp_pila(yyout,$$.direcciones,$$.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  REGLA AÑADIDA - BUCLE_EXP
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
bucle_exp: TOK_WHILE {
    $$.etiqueta = etiqueta++;
    while_inicio(yyout,$$.etiqueta);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 54
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
lectura: TOK_SCANF TOK_IDENTIFICADOR {

      fprintf(stdout, ";R54:\t<lectura> ::= scanf <identificador>\n");


      if(tablaSimbolosLocal != NULL){ //HAY AMBITO LOCAL

        aux = UsoExclusivoLocal($2.lexema);

        if(aux != NULL){

            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                return -1;
            }

            /*LEER SI ES UN PARAMETRO*/
            if(aux->categoria == PARAMETRO){

                escribirParametro(yyout,aux->adicional2,num_parametros_actual);
                if(aux->tipo == INT){
                    leer_en_pila(yyout,0);
                }else{
                    leer_en_pila(yyout,1);
                }
            }else{/*LEER SI ES UNA LOCAL*/

                escribirVariableLocal(yyout,aux->adicional2);
                if(aux->tipo == INT){
                    leer_en_pila(yyout,0);
                }else{
                    leer_en_pila(yyout,1);
                }
            }
        }else{
            aux = UsoGlobal($2.lexema);

            if(aux != NULL){
                if(aux->categoria == FUNCION){
                    fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                    return -1;
                }

                if(aux->clase == VECTOR){
                    fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                    return -1;
                }

                if(aux->tipo == INT){
                    leer(yyout,$2.lexema,0);
                }else if(aux->tipo == BOOLEAN){
                    leer(yyout,$2.lexema,1);
                }


            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, $2.lexema);
                return -1;
            }
        }

    }else{

        aux = UsoGlobal($2.lexema);

        if(aux != NULL){
            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                return -1;
            }

            if(aux->tipo == INT){
                leer(yyout,$2.lexema,0);
            }else if(aux->tipo == BOOLEAN){
                leer(yyout,$2.lexema,1);
            }


        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, $2.lexema);
            return -1;
        }

    }

};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 56
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
escritura: TOK_PRINTF exp {
    fprintf(stdout, ";R56:\t<escritura> ::= printf <exp>\n");
    if($2.tipo == INT){
        escribir(yyout,$2.direcciones,0);
    }else{
        escribir(yyout,$2.direcciones,1);
    }
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 61
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
retorno_funcion: TOK_RETURN exp {
    fprintf(stdout, ";R61:\t<retorno_funcion> ::= return <exp>\n");

    if(tablaSimbolosLocal == NULL){
      fprintf(stdout,"****Error Semantico en la linea %d: Sentencia de retorno fuera del cuerpo de una función.",line);
      return -1;
    }

    retornarFuncion(yyout,$2.direcciones);
    tipo_retorno = $2.tipo;
    fn_return++;


};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 72
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
exp: exp TOK_MAS exp {
    fprintf(stdout, ";R72:\t<exp> ::= <exp> + <exp>\n");
    if($1.tipo == INT && $3.tipo == INT){

        $$.tipo = INT;
        $$.direcciones = 0;

        sumar(yyout,$1.direcciones,$3.direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }


}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 73
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | exp TOK_MENOS exp {
    fprintf(stdout, ";R73:\t<exp> ::= <exp> - <exp>\n");
    if($1.tipo == INT && $3.tipo == INT){

        $$.tipo = INT;
        $$.direcciones = 0;

        restar(yyout,$1.direcciones,$3.direcciones);

    }else{
        fprintf(stdout, "****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 74
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | exp TOK_DIVISION exp {
    fprintf(stdout, ";R74:\t<exp> ::= <exp> / <exp>\n");
    if($1.tipo == INT && $3.tipo == INT){

        $$.tipo = INT;
        $$.direcciones = 0;

        dividir(yyout, $1.direcciones, $3.direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 75
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | exp TOK_ASTERISCO exp {
    fprintf(stdout, ";R75:\t<exp> ::= <exp> * <exp>\n");
    if($1.tipo == INT && $3.tipo == INT){

        $$.tipo = INT;
        $$.direcciones = 0;

        multiplicar(yyout,$1.direcciones,$3.direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 76
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_MENOS exp %prec MENOSU {
    fprintf(stdout, ";R76:\t<exp> ::= - <exp>\n");
    if($2.tipo == INT){

        $$.tipo = INT;
        $$.direcciones = 0;

        cambiar_signo(yyout,$2.direcciones);
    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 77
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | exp TOK_AND exp {
    fprintf(stdout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;

        y(yyout,$1.direcciones,$3.direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 78
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | exp TOK_OR exp {
    fprintf(stdout, ";R78:\t<exp> ::= <exp> || <exp>\n");
    if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;

        o(yyout,$1.direcciones,$3.direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n", line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 79
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_NOT exp {
    fprintf(stdout, ";R79:\t<exp> ::= ! <exp>\n");
    if($2.tipo == BOOLEAN){
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;

        no(yyout,$2.direcciones,cuantos_no);
        cuantos_no++;

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n",line);
        return -1;
    }
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 80
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_IDENTIFICADOR {
    fprintf(stdout, ";R80:\t<exp> ::= <identificador>\n");

    strcpy($$.lexema,$1.lexema);

    if(tablaSimbolosLocal != NULL){
        aux = UsoExclusivoLocal($1.lexema);
        if(aux != NULL){ //BUSQUEDA EN LOCAL

            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, $1.lexema);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, $1.lexema);
                return -1;
            }


            if(aux->categoria == VARIABLE){
                escribirVariableLocal(yyout,aux->adicional2);
            }else if(aux->categoria == PARAMETRO){
                escribirParametro(yyout,aux->adicional2,num_parametros_actual);
            }

            $$.tipo = aux->tipo;
            $$.direcciones = 1;

        }else{


            aux =  UsoGlobal($1.lexema);

            if(aux != NULL){

                if(aux->categoria == FUNCION){
                    fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, $1.lexema);
                    return -1;
                }

                if(aux->clase == VECTOR){
                    fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, $1.lexema);
                    return -1;
                }

                escribir_operando(yyout,$1.lexema,1); //Direccion

                $$.tipo = aux->tipo;
                $$.direcciones = 1;


            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, $1.lexema);
                return -1;
            }
        }

    }else{ //BUSQUEDA EN GLOBAL

        aux =  UsoGlobal($1.lexema);
        if(aux != NULL){
            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, $1.lexema);
                return -1;
            }

            if(aux->clase == VECTOR){
              fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, $1.lexema);
                return -1;
            }

            if(en_explist == 0){
              escribir_operando(yyout,$1.lexema,1); //Direccion
            }else{
              escribir_operando(yyout,$1.lexema,1); //Direccion
              operandoEnPilaAArgumento(yyout,1); //DUDAS
            }

            $$.tipo = aux->tipo;
            $$.direcciones = 1;

        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, $1.lexema);
            return -1;
        }

    }


}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 81
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | constante {
    fprintf(stdout, ";R81:\t<constante>\n");
    snprintf(aux_char, sizeof(aux_char), "%d", $1.valor_entero);
    escribir_operando(yyout,aux_char,$1.direcciones);
    $$.tipo = $1.tipo;
    $$.direcciones = $1.direcciones;
    $$.valor_entero = $1.valor_entero;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 82
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
    fprintf(stdout, ";R82:\t<exp> ::= ( <exp> )\n");
    $$.tipo = $2.tipo;
    $$.direcciones = $2.direcciones;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 83
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
    fprintf(stdout, ";R83:\t<exp> ::= ( <comparacion> )\n");
    $$.tipo = $2.tipo;
    $$.direcciones = $2.direcciones;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 85
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | elemento_vector {
    fprintf(stdout, ";R85:\t<exp> ::= <elemento_vector>\n");

    $$.tipo = $1.tipo;
    $$.direcciones = $1.direcciones;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 88
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
    | TOK_IDENTIFICADOR activar_en_explist TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
    fprintf(stdout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");

    if((aux = UsoLocal($1.lexema)) == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d: Acceso a funcion no declarada (%s).\n",line,$1.lexema);
        return -1;
    }


    if(aux->categoria != FUNCION){
        fprintf(stdout,"****Error Semantico en la linea %d: Variable %s no es de categoria funcion.\n",line,$1.lexema);
        return -1;
    }

    if(aux->adicional1 != comprobacion_parametros){
        fprintf(stdout,"****Error Semantico en la linea %d:Numero incorrecto de parametros en llamada a funcion.\n",line);
        return -1;
    }

    llamarFuncion(yyout, aux->lexema, aux->adicional1);
    en_explist = 0;
    $$.tipo = aux->tipo;
    $$.direcciones = 0;
};

activar_en_explist: {
    en_explist = 1;
}


/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 89
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
lista_expresiones: exp resto_lista_expresiones {
    fprintf(stdout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
    comprobacion_parametros = comprobacion_parametros + 1;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 90
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";R90:\t<lista_expresiones> ::=\n");
    comprobacion_parametros = 0;

};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 91
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {
    fprintf(stdout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
    comprobacion_parametros = comprobacion_parametros + 1;

}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 92
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | /* LAMBDA */ {
    fprintf(stdout, ";R92:\t<resto_lista_expresiones> ::=\n");
    comprobacion_parametros = 0;

};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 93
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
comparacion: exp TOK_IGUAL exp {
    fprintf(stdout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    $$.tipo = BOOLEAN;
    $$.direcciones = 0;

    igual(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 94
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | exp TOK_DISTINTO exp {
    fprintf(stdout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    $$.tipo = BOOLEAN;
    $$.direcciones = 0;

    distinto(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 95
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | exp TOK_MENORIGUAL exp {
    fprintf(stdout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    $$.tipo = BOOLEAN;
    $$.direcciones = 0;

    menor_igual(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 96
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | exp TOK_MAYORIGUAL exp {
    fprintf(stdout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");

    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    mayor_igual(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);


    $$.tipo = BOOLEAN;
    $$.direcciones = 0;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 97
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | exp TOK_MENOR exp {
    fprintf(stdout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");

    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    $$.tipo = BOOLEAN;
    $$.direcciones = 0;

    menor(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 98
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | exp TOK_MAYOR exp {

    fprintf(stdout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");

    if($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    $$.tipo = BOOLEAN;
    $$.direcciones = 0;

    mayor(yyout,$1.direcciones,$3.direcciones,num_comparaciones++);
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 99
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
constante: constante_logica{
    fprintf(stdout, ";R99:\t<constante> ::= <constante_logica>\n");
    $$.tipo=$1.tipo;
    $$.direcciones=$1.direcciones;
    $$.valor_entero=$1.valor_entero;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 100
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | constante_entera {
    fprintf(stdout, ";R100:\t<constante> ::= <constante_entera>\n");
    $$.tipo=$1.tipo;
    $$.direcciones=$1.direcciones;
    $$.valor_entero=$1.valor_entero;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 102
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
constante_logica: TOK_TRUE {
    fprintf(stdout, ";R102:\t<constante_logica> ::= true\n");
    $$.tipo=BOOLEAN;
    $$.direcciones=0;
    $$.valor_entero=1;
}
/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 103
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
        | TOK_FALSE {
    fprintf(stdout, ";R103:\t<constante_logica> ::= false\n");
    $$.tipo=BOOLEAN;
    $$.direcciones=0;
    $$.valor_entero=0;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 104
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
constante_entera: TOK_CONSTANTE_ENTERA {
    fprintf(stdout, ";R104:\t<constante_entera> ::= <numero>\n");
    $$.tipo=INT;
    $$.direcciones=0;
    $$.valor_entero=$1.valor_entero;
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA 108
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
identificador: TOK_IDENTIFICADOR {
    fprintf(stdout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

    if(tablaSimbolosLocal != NULL){ //EXISTE LA LOCAL
        aux = UsoExclusivoLocal($1.lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            fprintf(stdout,"****Error Semantico en linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA LOCAL MIRANDO QUE SU CLASE SEA ESCALAR, NO PUEDE SER UN VECTOR
            if(clase_actual != ESCALAR){
                //ERROR DE DECLARACION, INDICAMOS
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s no es de clase escalar.\n",line, $1.lexema);
                return -1;
            }else{
                //INSERTARLO EN LA TABLA LOCAL
                if(DeclararLocal($1.lexema,VARIABLE,tipo_actual,clase_actual,0,pos_variable_local_actual) == OK){
                    pos_variable_local_actual++;
                    num_variables_locales_actual++;
                }else{
                    fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear variable (%s).",line, $1.lexema);
                    return -1;
                }
            }
        }
    }else{
        aux = UsoExclusivoGlobal($1.lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA GLOBAL(Revisar parametros)
            if(DeclararGlobal($1.lexema,VARIABLE,tipo_actual,clase_actual,tamanio_vector_actual,0) == OK){
                tamanio_vector_actual=0;
            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear variable (%s).",line, $1.lexema);
                return -1;
            }

        }
    }
};

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  PRODUCCION REGLA IDPF
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
idpf: TOK_IDENTIFICADOR{

    if(tablaSimbolosLocal != NULL){
        aux = UsoExclusivoLocal($1.lexema);
        if(aux != NULL){
            fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            if(DeclararLocal($1.lexema,PARAMETRO,tipo_actual,ESCALAR,0,pos_parametro_actual) == OK){
                pos_parametro_actual++;
                num_parametros_actual++;
            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear parametro (%s).",line,$1.lexema);
                return -1;
            }
        }
    }else{
        fprintf(stdout,"****Ambito local no esta abierto\n");
        return -1;
    }
};

%%

/*-------------------------------------------------------------------------------------------------------------------------*/
/*  CODIGO DE ERRORES SINTACTICOS
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
void yyerror (const char* err){
        if(error == 0){
                fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col-yyleng);
        }
        error = 0;
}
