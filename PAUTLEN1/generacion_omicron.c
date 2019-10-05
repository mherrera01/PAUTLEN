
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generacion_omicron.h"



/************ G14 **********************************************************************/

void escribir_cabecera_compatibilidad(FILE* fpasm)
{
/* FUNCIÓN PARA PODER HACER EL CÓDIGO MULTIPLATAFORMA U OTROS PARÁMETROS GENERALES TAL VEZ SE PUEDA QUEDAR VACÍA */


/*
segment compatibilidad
resd xx 1 34
kdfasldjf
*/
fprintf(fpasm, “segment compatibilidadn”);


}

/************** G13 ********************************************************************/

void escribir_subseccion_data(FILE* fpasm)
{
/* FUNCIÓN PARA ESCRIBIR LA SECCIÓN .data:
	MENSAJES GENERALES (TEXTOS)
	VARIABLES AUXILIARES NECESARIAS EN EL COMPILADOR QUE DEBAN TENER UN VALOR CONCRETO */
	
}


/*********** G12 ***********************************************************************/

void escribir_cabecera_bss(FILE* fpasm)
{
/* FUNCIÓN PARA ESCRIBIR EL INICIO DE LA SECCIÓN .bss:
	AL MENOS HAY QUE DECLARAR LA VARIABLE AUXILIAR PARA GUARDAR EL PUNTERO DE PILA __esp
*/




}




/*********** G11  **********************************************************************/

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano)
/* tipo no hace falta porque para nosotros todo es entero en esta versión, se deja por compatibilidad con futuras versiones*/
{
/* GENERA EL CÓDIGO ASOCIADO EN LA SECCIÓN .bss PARA DECLARAR UNA VARIABLE CON
	SU NOMBRE (HAY QUE PRECEDER DE _)
	EL TAMANO (1 PARA VARIABLES QUE NO SEAN VECTORES O SU TAMANO EN OTRO CASO
	TIPO NOSOTROS USAREMOS ESTE AÑO ENTERO O BOOLEANO

*/
}


/************** G10 **********************************************************************/

void escribir_segmento_codigo(FILE* fpasm)
{
/* ESCRIBE EL INICIO DE LA SECCIÓN DE CÓDIGO
	DECLARACIONES DE FUNCIONES QUE SE TOMARAN DE OTROS MODULOS
	DECLARACION DE main COMO ETIQUETA VISIBLE DESDE EL EXTERIOR
*/

}


/*********  G9 *************************************************************************/

void escribir_inicio_main(FILE* fpasm)
{
/* ESCRIBE EL PRINCIPIO DEL CÓDIGO PROPIAMENTE DICHO
	ETIQUETA DE INICIO
	SALVAGUARDA DEL PUNTERO DE PILA (esp) EN LA VARIABLE A TAL EFECTO (__esp)

*/

fprintf(fpasm, “main:\n\tmov dword [__esp] , esp\n”);

}


/***************** G8 *****************************************************************/

void escribir_fin(FILE* fpasm)
{
/* ESCRITURA DEL FINAL DEL PROGRAMA
	GESTIÓN DE ERROR EN TIEMPO DE EJECUCIÓN (DIVISION POR 0)
	RESTAURACION DEL PUNTERO DE PILA A PARTIR DE LA VARIABLE __esp
	SENTENCIA DE RETORNO DEL PROGRAMA
*/


/*
    mov dword esp, [__esp]
    ret
*/
}


/*************G7 *********************************************************************/

void escribir_operando(FILE* fpasm, char *nombre, int es_variable)
{
/* SE INTRODUCE EL OPERANDO nombre EN LA PILA
	SI ES UNA VARIABLE (es_variable == 1) HAY QUE PRECEDER EL NOMBRE DE _
	EN OTRO CASO, SE ESCRIBE TAL CUAL
*/
	char * auxiliar = "push dword ";
	char * elemento1 = "[_";
	char * elemento2 = "]";

	
	if(fpasm == NULL){
		return;
	}
	
	if(es_variable == 1){ //NOMBR
		strcat(elemento1,nombre); //[_x
		strcat(elemento1,elemento2);//[_x]
		strcat(auxiliar,elemento); //push dword _x
		fprintf(fpasm,auxiliar);
	}else{ //NUMERO
		auxiliar = strcat (auxiliar, nombre); //push dword 32
		fprintf(fpasm,auxiliar);
	}



}


/************ G6 **********************************************************************/

void asignar(FILE* fpasm, char *nombre, int es_variable)
{
/* ESCRIBE EL CÓDIGO PARA REALIZAR UNA ASIGNACIÓN DE LO QUE ESTÉ EN LA CIMA DE LA PILA A LA VARIABLE nombre
	SE RECUPERA DE LA PILA LO QUE HAYA POR EJEMPLO EN EL REGISTRO eax
	SI es_variable == 0 (ES UN VALOR) DIRECTAMENTE SE ASIGNA A LA VARIABLE _nombre
	EN OTRO CASO es_variable == 1 (ES UNA DIRECCIÓN, UN NOMBRE DE VARIABLE) HAY QUE OBTENER SU VALOR DESREFERENCIANDO
EL VALOR ES [eax]
*/
if(es_variable==0){
	fprintf(fpasm, “pop dword _nombre”
}

}


/*************** G5 *******************************************************************/

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* GENERA EL CÓDIGO PARA SUMAR LO QUE HAYA EN LAS DOS PRIMERAS (DESDE LA CIMA)
POSICIONES DE LA PILA, TENIENDO EN CUENTA QUE HAY QUE INDICAR SI SON DIRECCIONES
 O NO (VER ASIGNAR) ¡¡¡CUIDADO CON EL ORDEN!!!

*/

}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* SIMILAR A SUMAR */

}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* SIMILAR A SUMAR (CUIDADO CON ECX) */

}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* SIMILAR A MULTIPLICAR (CUIDADO CON LA EXTENSIÓN DE SIGNO PREVIA) */

}

void o(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* SIMILAR A SUMAR */

}


void y(FILE* fpasm, int es_variable_1, int es_variable_2)
{
/* SIMILAR A SUMAR */

}


/************** G4 ********************************************************************/

void cambiar_signo(FILE* fpasm, int es_variable)
{
/* GENERA EL CÓDIGO PARA CAMBIAR DE SIGNO LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO O UNA DIRECCION (VER ASIGNAR)

*/

}


/**********   G3 ************************************************************************/

void no(FILE* fpasm, int es_variable, int cuantos_no)
{
/* GENERA EL CÓDIGO PARA NEGAR COMO VALOR LÓGICO LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO O UNA DIRECCION (VER ASIGNAR)
COMO ES NECESARIO UTILIZAR ETIQUETAS, SE SUPONE QUE LA VARIABLE cuantos_no ES UN
CONTADOR QUE ASEGURA QUE UTILIZARLO COMO AÑADIDO AL NOMBRE DE LAS ETIQUETAS QUE
USEMOS (POR EJEMPLO cierto: O falso: ) NOS ASEGURARÁ QUE CADA LLAMADA A no
UTILIZA UN JUEGO DE ETIQUETAS ÚNICO

*/

/* BASICAMENTE HAY QUE GENERAR ESTO
        cmp eax, 0
        je _uno
        push dword 0
        jmp _fin_not
_uno:   push dword 1
_fin_not:
*/

}


/**************** G2 ******************************************************************/

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
{
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LAS DOS PRIMERAS (DESDE LA CIMA)
POSICIONES DE LA PILA ES IGUAL, TENIENDO EN CUENTA QUE HAY QUE INDICAR SI SON
DIRECCIONES O NO
*/

/*

*/

}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LAS DOS PRIMERAS (DESDE LA CIMA)
POSICIONES DE LA PILA ES DISTINTO, TENIENDO EN CUENTA QUE HAY QUE INDICAR SI SON
DIRECCIONES O NO
*/
{

}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
 ES MENOR O IGUAL A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
 SI SON DIRECCIONES O NO
*/
{

}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
 ES MAYOR O IGUAL A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
 SI SON DIRECCIONES O NO
*/
{

}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
 ES MENOR A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
 SI SON DIRECCIONES O NO
*/
{

}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta)
/* GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
 ES MAYOR A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
 SI SON DIRECCIONES O NO
*/
{

}


/************ G1 **********************************************************************/

void leer(FILE* fpasm, char* nombre, int tipo)
{
/* GENERA EL CÓDIGO PARA LEER UNA VARIABLE DE NOMBRE nombre Y TIPO tipo (ESTE
AÑO SÓLO USAREMOS ENTERO Y BOOLEANO) DE CONSOLA LLAMANDO A LAS CORRESPONDIENTES
FUNCIONES DE ALFALIB (scan_int Y scan_boolean)

*/

}


void escribir(FILE* fpasm, int es_variable, int tipo)
{
/* GENERA EL CÓDIGO PARA ESCRIBIR POR PANTALLA LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO (es_referncia == 0) O UNA
DIRECCION (es_variable == 1) Y QUE HAY QUE LLAMAR A LA CORRESPONDIENTE
FUNCIÓN DE ALFALIB (print_int O print_boolean) DEPENDIENTO DEL TIPO (tipo == BOOLEANO
O ENTERO )
*/


}

