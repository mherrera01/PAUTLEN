#include <stdio.h>
#include <stdlib.h>
#include "generacion.h"


void escribir_cabecera_bss(FILE* fpasm){
    fprintf(fpasm, "\nsegment .bss\n\t__esp resd 1");
}

void escribir_subseccion_data(FILE* fpasm){
    fprintf(fpasm, "\nsegment .data");
    fprintf(fpasm, "\n\terr_div0 db \"Error al dividir entre 0\",0");
}

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
    fprintf(fpasm, "\n\t_%s resd %d", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
    fprintf(fpasm, "\nsegment .text\n\tglobal main\n\textern scant_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern alfa_malloc, alfa_free, ld_float");
}

void escribir_inicio_main(FILE* fpasm){
    fprintf(fpasm, "\nmain:\n\tmov dword [__esp], esp"); //BIEN A FALTA DE PROBAR
}

void escribir_fin(FILE* fpasm){
	fprintf(fpasm,"\n\tjmp near fin");
	fprintf(fpasm,"\ndivision_cero:");
	fprintf(fpasm,"\n\tpush dword err_div0\n\tcall print_string\n\tadd esp, 4\n\tcall print_enfofline\njmp near fin");
	fprintf(fpasm, "\nfin:");
    fprintf(fpasm, "\n\tmov dword esp, [__esp]");
    fprintf(fpasm, "\n\tret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
    if(es_variable == 1){
        fprintf(fpasm, "\n\tpush dword _%s", nombre);
    }else{
        fprintf(fpasm, "\n\tpush dword %s", nombre);
    }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
    fprintf(fpasm,"\n\tpop dword eax");
	if(es_variable == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	fprintf("\n\tmov dowrd [_%s], eax",nombre);
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\tadd eax, ebx");
	fprintf(fpasm, "\n\tpush dword eax");

}
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\tsub eax, ebx");
	fprintf(fpasm, "\n\tpush dword eax");
}
void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
		fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
		fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\timul ebx");
	fprintf(fpasm, "\n\tpush dword eax");

}
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
		fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
		fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\tmov dword edx, 0");
	fprintf(fpasm, "\n\tcmp ebx, edx");
	fprintf(fpasm, "\n\tje near division_cero");

	fprintf(fpasm, "\n\tidiv ebx");
	fprintf(fpasm, "\n\tpush dword eax");

}
void o(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\tor eax, ebx");
	fprintf(fpasm, "\n\tpush dword eax");
}
void y(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\n\tpop dword ebx");
	fprintf(fpasm, "\n\tpop dword eax");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword eax, [eax]");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\n\tmov dword ebx, [ebx]");
	}

	fprintf(fpasm, "\n\tand eax, ebx");
	fprintf(fpasm, "\n\tpush dword eax");
}

void cambiar_signo(FILE* fpasm, int es_variable){ //BIEN A FALTA DE PROBAR
	fprintf(fpasm,"\n\tpop dword eax");
	
	if(es_variable == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	fprintf(fpasm,"\n\tneg eax");
	fprintf(fpasm,"\n\tpush dword eax");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){ //BIEN A FALTA DE PROBAR
	
	fprintf(fpasm, "\n\tpop dword ecx");
    
	if(es_variable == 1){
        fprintf(fpasm, "\n\tmov dword ecx, [ecx]");
	}
	
    fprintf(fpasm, "\n\tmov dword eax, 0");
    fprintf(fpasm, "\n\tcmp eax, ecx");
    fprintf(fpasm, "\n\tje near positivo_negativo%d",cuantos_no);

    fprintf(fpasm, "\n\tmov dword eax, 0");
    fprintf(fpasm, "\n\tpush dword eax");
    fprintf(fpasm, "\n\tjmp near continua_%d", cuantos_no);

    fprintf(fpasm, "\npositivo_negativo%d:", cuantos_no);
    fprintf(fpasm, "\n\tmov dword eax, 1");
    fprintf(fpasm, "\n\tpush dword eax");
	
    fprintf(fpasm, "\ncontinua_%d:", cuantos_no);
}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjz near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
	
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjnz near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjle near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjge near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjl near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	fprintf(fpasm,"\n\tpop dword ecx\n\tpop dowrd eax");
	
	if(es_variable1 == 1){
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
	}
	
	if(es_variable2 == 1){
		fprintf(fpasm,"\n\tmov dword ecx, [ecx]");
	}
	
	fprintf(fpasm,"\n\tcmp eax,ecx");
	fprintf(fpasm,"\n\tjg near true_%d", etiqueta);

	fprintf(fpasm,"\n\tmov dword eax, 0");
	fprintf(fpasm,"\n\tpush dword eax");
	fprintf(fpasm,"\n\tjmp near continua_%d", etiqueta);
	
	fprintf(fpasm,"\ntrue_%d:",etiqueta);
	fprintf(fpasm,"\n\tmov dword eax,1");
	fprintf(fpasm,"\n\tpush dword eax");
	
	fprintf(fpasm,"\n\tcontinua_%d:",etiqueta);
}

void leer(FILE* fpasm, char* nombre, int tipo){
	
	fprintf(fpasm,"\n\tpush dword _%s",nombre);
	
	if(tipo == ENTERO){
		fprintf(fpasm,"\n\tcall scan_int");
	}else{
		fprintf(fpasm,"\n\tcall scan_boolean");
	}
	
	fprintf(fpasm,"\n\tadd esp, 4");
}

void escribir(FILE* fpasm, int es_variable, int tipo){
	
	if(es_variable == 1){
		fprintf(fpasm,"\n\tpop dword eax");
		fprintf(fpasm,"\n\tmov dword eax, [eax]");
		fprintf(fpasm,"\n\tpush dword eax");
	}
	
	if(tipo == ENTERO){
		fprintf(fpasm,"\n\tcall print_int");
	}else{
		fprintf(fpasm,"\n\tcall print_boolean");
	}
	
	fprintf(fpasm,"\n\tadd esp, 4");
	fprintf(fpasm,"\n\tcall print_endofline");
}