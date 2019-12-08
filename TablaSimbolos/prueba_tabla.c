#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"

int main(int argc, char* argv[])
{
    int ret_lex = 0;
    char linea[1024];
    char * token;
    char * token2;
    int global=1;
    int contador=0;
	FILE * yyin;
	FILE * yyout;
	int valor=0;
	INFO_SIMBOLO * entrada;
	int aux;

    if(argc < 3){
        fprintf(stderr, "Error en el numero de argumentos. ./prueba_tabla <fichero_entrada> <fichero_salida>");
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if(!yyin){
        fprintf(stderr, "No ha sido posible abrir el fichero de entrada.");
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if(!yyout){
        fprintf(stderr, "No ha sido posible ");
        return -1;
    }


    while(fgets(linea,1024,(FILE*) yyin)){
	    char * token;
	    char* rest = linea;
	  	char * resultado[2];
	  	contador = 0;

	    while ((token = strtok_r(rest, " ", &rest))) {
	    	resultado[contador]= (char*)malloc(strlen(token) + 1);
	    	strtok(token,"\n");
	        strcpy(resultado[contador],token);
	        contador++; //Numero de elementos en este caso 2
	    }

	    if(strncmp(resultado[0],"cierre",7) == 0 && atoi(resultado[1]) == -999){ //CIERRE AMBITO
	    	printf("CIERRE \n");
	    	CerrarFuncion();
	    	//ImprimirTablaGlobal();
	    	global=1;
	    	fprintf(yyout,"%s\n",resultado[0]);
	    	aux = contador - 1;
		    while(aux>= 0){
		    	free(resultado[aux]);
		    	aux--;
		    }
	    	continue;
	    }


	    if(contador == 2 && atoi(resultado[1]) < 0){ //APERTURA DE AMBITO
	    	printf("FUNCION \n");
	    	valor=atoi(resultado[1]);
	    	DeclararFuncion(resultado[0],FUNCION,INT,ESCALAR,valor,0);
	    	ImprimirTablaGlobal();
	    	ImprimirTablaLocal();
	    	global=0;
	    	fprintf(yyout, "%s\n", resultado[0]);
	    	aux = contador - 1;
		    while(aux>= 0){
		    	free(resultado[aux]);
		    	aux--;
		    }
	    	continue;
	    }

	    if(contador == 2 && atoi(resultado[1]) >= 0){ //INSERCION
	    	if(global==1){
	    		printf("AMBITO GLOBAL ==> 2 palabras INSERTAMOS\n");
		    	valor = atoi(resultado[1]);
		    	if(DeclararGlobal(resultado[0],VARIABLE,INT,ESCALAR,valor,0) == OK){
		    		printf("Elemento %s insertado en la tabla GLOBAL\n",resultado[0]);
		    		fprintf(yyout,"%s\n",resultado[0]);
		    	}else{
		    		printf("Elemento %s no insertado en la tabla GLOBAL\n",resultado[0]);
		    		fprintf(yyout,"-1 %s\n",resultado[0]);	    		
		    	}
		    	ImprimirTablaGlobal();
	    	}else if(global==0){
	    		printf("AMBITO LOCAL ==> 2 palabras INSERTAMOS\n");
		    	valor = atoi(resultado[1]);
		    	if(DeclararLocal(resultado[0],VARIABLE,INT,ESCALAR,valor,0) == OK){
					printf("Elemento %s insertado en la tabla LOCAL\n",resultado[0]);
					fprintf(yyout,"%s\n",resultado[0]);
		    	}else{
		    		printf("Elemento %s no insertado en la tabla LOCAL\n",resultado[0]);
		    		fprintf(yyout,"-1 %s\n",resultado[0]);	  
		    	}
		    	ImprimirTablaLocal();
	    	}
	    }

	    if(contador == 1){ //BUSQUEDA
	    	if(global==1){
	    		printf("AMBITO GLOBAL ==> 1 palabra BUSCAMOS\n");
		    	if((entrada = UsoGlobal(resultado[0])) != NULL){
		    		printf("Elemento %s encontrado en la tabla GLOBAL\n",resultado[0]);
		    		fprintf(yyout,"%s %d\n",entrada->lexema, entrada->adicional1);
		    	}else{
		    		printf("Elemento %s no encontrado en la tabla GLOBAL\n",resultado[0]);
		    		fprintf(yyout,"%s -1\n",resultado[0]);
		    	}
	    	}else if(global==0){
	    		printf("AMBITO LOCAL ==> 1 palabra BUSCAMOS\n");
		    	if((entrada = UsoLocal(resultado[0])) != NULL){
		    		printf("Elemento %s encontrado en la tabla LOCAL\n",resultado[0]);
		    		fprintf(yyout,"%s %d\n",entrada->lexema, entrada->adicional1);
		    	}else{
		    		printf("Elemento %s no encontrado en la tabla LOCAL\n",resultado[0]);
		    		fprintf(yyout,"%s -1\n",resultado[0]);
		    	}
	    	}
	    }

	    
	    printf("\n");



	    aux = contador - 1;
	    while(aux>= 0){
	    	free(resultado[aux]);
	    	aux--;
	    }
   
    }

	LimpiarTablas();    
    

    fclose(yyin);
    fclose(yyout);

    return 0;
}