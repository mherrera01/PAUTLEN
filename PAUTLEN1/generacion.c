#include "generacion.h"


void escribir_cabecera_bss(FILE* fpasm){
    fprintf(fpasm, "segment.bss\n\t__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
    fprintf(fpasm, "segment.data\n");
    fprintf(fpasm, "err_div0 db \"Error al dividir entre 0\",0\n");
}

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
    if(!fpasm || strcmp(nombre, "") == 0 || !nombre || ((tipo != ENTERO) && (tipo != BOOLEANO)) || tamano <= 0){
        fprintf(stderr, "ERROR EN FUN: declarar_variable\n");
        return;
    }

    fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
    fprintf(fpasm, "segment.text\n\tglobal main\n\textern scant_int print_int scan_float print_boolean\n\textern print_endofline print_blank print_string\n\textern alfa_malloc alfa_free ld_float");
}

void escribir_inicio_main(FILE* fpasm){
    fprintf(fpasm, "main:\n\tmov doword [__esp], esp\n");
}

void escribir_fin(FILE* fpasm){
    printf(fpasm, "jmp fin\ndivision_cero:\n\tpush dword err_div0\n\tcall print_string\n\tadd esp, 4\n\tcall printf_endofline\n\tjmp fin\nfin:\n\tmov dword esp, [__esp]\n\tret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
    if(es_variable == 1){
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
    }else{
        fprintf(fpasm, "\tpush dword %s\n", nombre);
    }

    return;
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
    if(es_variable == 0){
        fprintf(fpasm, "\tpop dword eax\n\tmov [_%s], eax\n", nombre);
    }
    else{
        fprintf(fpasm, "\tpop dword eax\n\tmov dword [_%s], [eax]\n", nombre);
    }

    return;
}


