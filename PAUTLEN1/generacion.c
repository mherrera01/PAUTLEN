#include "generacion.h"


void escribir_cabecera_bss(FILE* fpasm){
    fprintf(fpasm, "segment .bss\n\t__esp resd 1\n"); //BIEN A FALTA DE PROBAR
}

void escribir_subseccion_data(FILE* fpasm){
    fprintf(fpasm, "segment .data\n");
    fprintf(fpasm, "err_div0 db \"Error al dividir entre 0\",0\n"); //BIEN A FALTA DE PROBAR
}

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
    if(!fpasm || strcmp(nombre, "") == 0 || !nombre || ((tipo != ENTERO) && (tipo != BOOLEANO)) || tamano <= 0){
        fprintf(stderr, "ERROR EN FUN: declarar_variable\n");
        return;
    }

    fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano); //BIEN A FALTA DE PROBAR
}

void escribir_segmento_codigo(FILE* fpasm){
    fprintf(fpasm, "segment .text\n\tglobal main\n\textern scant_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern alfa_malloc, alfa_free, ld_float");
} //CORREGIDA A FALTA DE PROBAR

void escribir_inicio_main(FILE* fpasm){
    fprintf(fpasm, "\nmain:\n\tmov doword [__esp], esp\n"); //BIEN A FALTA DE PROBAR
}

void escribir_fin(FILE* fpasm){
    printf(fpasm, "jmp fin\ndivision_cero:\n\tpush dword err_div0\n\tcall print_string\n\tadd esp, 4\n\tcall printf_endofline\n\tjmp fin\nfin:\n\tmov dword esp, [__esp]\n\tret\n"); //FALTA REVISAR
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){ //BIEN A FALTA DE PROBAR
    if(es_variable == 1){
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
    }else{
        fprintf(fpasm, "\tpush dword %s\n", nombre);
    }

    return;
}

void asignar(FILE* fpasm, char* nombre, int es_variable){ //BIEN A FALTA DE PROBAR
    if(es_variable == 0){
        fprintf(fpasm, "\tpop dword eax\n\tmov [_%s], eax\n", nombre);
    }
    else{
        fprintf(fpasm, "\tpop dword eax\n\tmov dword [_%s], [eax]\n", nombre);
    }

    return;
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){ //BIEN A FALTA DE PROBAR
	printf(fpasm, "\n\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\tadd eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");

}
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
	printf(fpasm, "\n\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\tsub eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
		fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\timul ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");

}
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
		fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\tmov dword edx, 0\n");
	fprintf(fpasm, "\tcmp ebx, edx\n");
	fprintf(fpasm, "\tje error_div_cero\n");

	fprintf(fpasm, "\tidiv ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");

}
void o(FILE* fpasm, int es_variable_1, int es_variable_2){
	printf(fpasm, "\n\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\tor eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void y(FILE* fpasm, int es_variable_1, int es_variable_2){
	printf(fpasm, "\n\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if(es_variable_1 == VARIABLE) {
	fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if(es_variable_2 == VARIABLE) {
	fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}

	fprintf(fpasm, "\tand eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}

void cambiar_signo(FILE* fpasm, int es_variable){
	
}

void no(FILE* fpasm, int es_variable, int cuantos_no){ //NO ESTA BIEN
	if(es_variable == 1{
		fprintf(fpasm,"\n\tpop dword eax");
		fprintf(fpasm,"\n\tcmp eax, 0");
		fprintf(fpasm,"\n\tje _uno");
		fprintf(fpasm,"\n\t push dword 0");
		fprintf(fpasm,"\n\t jmp _fin_not");
		fprintf(fpasm,"\n_uno: push dword 1");
		fprintf(fpasm,"\n_fin_not: ");
	}else{
		fprintf(fpasm,"\n\tpop dword eax");
		fprintf(fpasm,"\n\tmov eax, [eax]");
		
	}
}

