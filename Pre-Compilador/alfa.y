%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "alfa.h"
    #include "tablaHash.h"
    #include "tablaSimbolos.h"
    #include "generacion.h"

    extern FILE *yyin;
    extern FILE *yyout;
    extern int yylex();
    void yyerror(const char* err);
    extern int line, col, error;
    extern int yyleng;
    extern TABLA_HASH * tablaSimbolosGlobal, * tablaSimbolosLocal;
    INFO_SIMBOLO * aux;

    TIPO tipoActual;
    TIPO retornoFuncion;
    CLASE claseActual;
    int tamanioVectorActual=0; //Tamanio del vector
    int posVariableLocalActual=1; //Posicion de variable global en ambitos de variables locales
    int numVariablesLocalesActual=0;
    int posParametroActual=0;
    int numParametrosActual=0;
    /*SIMBOLOS*/
%}
%union
        {
            tipo_atributos atributos;
        }

/*token's con valor semantico*/

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA

/*token's sin valor semantico*/

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
%token TOK_IDENTIFICADOR
%token TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

/*simbolos no terminales con atributos semantico*/

%type <atributos> exp
%type <atributos> comparaciones
%type <atributos> elemento_vector
%type <atributos> asignacion
%type <atributos> condicional
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> constante
%type <atributos> fn_name

/*FALTAN MUCHOS MAS*/

%left TOK_ASIGNACION
%left TOK_AND TOK_OR
%left TOK_IGUAL TOK_DISTINTO
%left TOK_MAYOR TOK_MENOR TOK_MAYORIGUAL TOK_MENORIGUAL
%left TOK_MAS TOK_MENOS
%left TOK_DIVISION TOK_ASTERISCO
%left TOK_NOT MENOSU
%left TOK_PARENTESISIZQUIERDO TOK_PARENTESISDERECHO TOK_CORCHETEIZQUIERDO TOK_CORCHETEDERECHO
%start programa

%%
programa: inicioTabla TOK_MAIN TOK_LLAVEIZQUIERDA escribirSegmentos declaraciones funciones escribirMain sentencias cierreTabla TOK_LLAVEDERECHA {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
;

inicioTabla:{
    /*INICIAMOS TABLAS*/
    CrearTablaGlobal();
}

escribirSegmentos:{
    /*Declarar variables y funciones correspondientes*/
    /*ESCRIBIR SUBSECCION DATOS Y SEGMENTO DE CODIGO*/
}

escribirMain:{
    /*ESCRIBIMOS MAIN(asm)*/
    escribir_inicio_main(yyout);
}

cierreTabla:{
    /*CERRAMOS TABLAS Y ESCRIBIRMOS FIN(asm)*/
    LimpiarTablas();
    escribir_fin(yyout);
}


















declaraciones: declaracion {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
            | declaracion declaraciones {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
;

declaracion: clase identificadores TOK_PUNTOYCOMA {fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
;

clase: clase_escalar { claseActual = ESCALAR; fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");}
    | clase_vector { claseActual = VECTOR; fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");}
;

clase_escalar: tipo {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");}
;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {

    tamanioVectorActual = $4.valor_entero;
    if((tamanioVectorActual < 1) || (tamanioVectorActual > MAX_TAMANIO_VECTOR)){
        printf("****Error Semantico en la linea %d: tamanio array superior al permitido\n", line);
        return -1;
    }

    fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
};

tipo: TOK_INT { tipoActual = INT; fprintf(yyout, ";R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {tipoActual = BOOLEAN; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");}
;

identificadores: identificador {fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");}
            | identificador TOK_COMA identificadores {fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
;








funciones: funcion funciones {fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
        | /* LAMBDA */ {fprintf(yyout, ";R21:\t<funciones> ::=\n");}
;

funcion: fn_declaracion sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");};

fn_declaracion: fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion{}

fn_name: TOK_FUNCION tipo TOK_IDENTIFICADOR{
    
    aux = UsoGlobal($3.lexema);

    if(aux != NULL){ //Error porque el identificador ya existe en este ambito
        printf("****Error Semantico en la linea %d: Declaracion doble de variable\n", line);
    }else{
        if(DeclararGlobal($3.lexema,FUNCION,tipoActual,claseActual,tamanioVectorActual,posVariableLocalActual) == OK){
            if(CrearTablaLocal() != NULL){
                if(DeclararLocal($3.lexema,FUNCION,tipoActual,claseActual,tamanioVectorActual,posVariableLocalActual) == OK){
                    posVariableLocalActual=1;
                    numVariablesLocalesActual=0;
                    posParametroActual=0;
                    numParametrosActual=0;
                    tamanioVectorActual=0;
                    retornoFuncion = tipoActual;
                    sprintf($$.lexema,"%s",$3.lexema);
                }else{
                    //ERROR INTERNO
                }
            }else{
                //ERROR INTERNO
            }
        }else{
            //ERROR INTERNO
        }
    }
}






parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                | /* LAMBDA */ {fprintf(yyout, ";;R24:\t<parametros_funcion> ::=\n");}
;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R25:\t <resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                        | /* LAMBDA */ {fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");}
;

parametro_funcion: tipo idpf {fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
;

declaraciones_funcion: declaraciones {fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                    | /* LAMBDA */ {fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");}
;

sentencias: sentencia {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");}
        | sentencia sentencias {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
;

sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
            | bloque {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");}
;
sentencia_simple: asignacion {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                | lectura {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
                | escritura {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
                | retorno_funcion {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
;

bloque: condicional {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
    | bucle {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");}
;

asignacion: identificador TOK_ASIGNACION exp {fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
        | elemento_vector TOK_ASIGNACION exp {fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
;

elemento_vector: identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
;

condicional: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
        | TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEIZQUIERDA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
;

bucle: TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
;

lectura: TOK_SCANF identificador {fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");}
;

escritura: TOK_PRINTF exp {fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");}
;

retorno_funcion: TOK_RETURN exp {fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
;

exp: exp TOK_MAS exp {fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");}
    | exp TOK_MENOS exp {fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");}
    | exp TOK_DIVISION exp {fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");}
    | exp TOK_ASTERISCO exp {fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");}
    | TOK_MENOS exp %prec MENOSU {fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");}
    | exp TOK_AND exp {fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");}
    | exp TOK_OR exp {fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");}
    | TOK_NOT exp {fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");}
    | identificador {fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");}
    | constante {fprintf(yyout, ";R81:\t<constante>\n");}
    | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");}
    | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");}
    | elemento_vector {fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");}
    | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
;

lista_expresiones: exp resto_lista_expresiones {fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
                | /* LAMBDA */ {fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");}
;

resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
                    | /* LAMBDA */ {fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");}
;

comparacion: exp TOK_IGUAL exp {fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");}
        | exp TOK_DISTINTO exp {fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");}
        | exp TOK_MENORIGUAL exp {fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
        | exp TOK_MAYORIGUAL exp {fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
        | exp TOK_MENOR exp {fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");}
        | exp TOK_MAYOR exp {fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");}
;

constante: constante_logica {fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");}
        | constante_entera {fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");}
;

constante_logica: TOK_TRUE {fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");}
                | TOK_FALSE {fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");}
;

constante_entera: TOK_CONSTANTE_ENTERA {fprintf(yyout, ";R104:\t<constante_entera> ::= <numero>\n");}
;

identificador: TOK_IDENTIFICADOR {fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

    if(tablaSimbolosLocal != NULL){ //EXISTE LA LOCAL
        aux = UsoExclusivoLocal($1.lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            //INDICARLO CON PRINT
            printf("****Error Semantico en linea %d: variable duplicada\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA LOCAL MIRANDO QUE SU CLASE SEA ESCALAR
            if(claseActual != ESCALAR){
                //ERROR DE DECLARACION, INDICAMOS
                printf("****Error Semantico en la linea %d: Variable local de tipo incorrecto\n",line);
                return -1;
            }else{
                //INSERTARLO EN LA TABLA LOCAL(Revisar parametros)
                if(DeclararLocal($1.lexema,VARIABLE,tipoActual,claseActual,tamanioVectorActual,posVariableLocalActual) == OK){
                    posVariableLocalActual++;
                    numVariablesLocalesActual++;
                    tamanioVectorActual=0;
                }else{
                    //ERROR INTERNO
                }
            }
        }
    }else{
        aux = UsoExclusivoGlobal($1.lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            //INDICARLO CON PRINT
            printf("****Error Semantico en la linea %d: variable duplicada\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA GLOBAL(Revisar parametros)
            if(DeclararGlobal($1.lexema,VARIABLE,tipoActual,claseActual,tamanioVectorActual,posVariableLocalActual) == OK){
                posVariableLocalActual++;
                numVariablesLocalesActual++;
                tamanioVectorActual=0;
            }else{
                //ERROR INTERNO
            }
            
        }
    }
}
;

idpf: TOK_IDENTIFICADOR{
    
    if(tablaSimbolosLocal != NULL){
        aux = UsoLocal($1.lexema);
        if(aux != NULL){
            printf("****Error Semantico en la linea %d: Acceso a la variable %s sin declarar\n", line, $1.lexema);
            return -1;
        }else{
            if(DeclararGlobal($1.lexema,PARAMETRO,tipoActual,claseActual,tamanioVectorActual,posParametroActual) == OK){
                posParametroActual++;
                numParametrosActual++;
                tamanioVectorActual=0;   
            }else{
                //ERROR INTERNO
            }
        }
    }else{
        printf("****Ambito local no esta abierto\n");
        printf("****Error Semantico en linea %d ,columna %d\n", line, col);
        return -1;
    }

};


%%

void yyerror (const char* err){
        if(error == 0){
                fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col-yyleng);
        }
        error = 0;
}