#!/bin/sh

if [ $# = 0  ]; then
echo "ejemplo => "
echo "sh PRODUCCION.sh CREAR_LIBRERIA generacion"
echo "sh PRODUCCION.sh EJECUTABLE_MAIN main_s0_1"
echo "sh PRODUCCION.sh EJECUTABLE_ASM  ejemploasm"
fi

if [ "$1" = "CREAR_LIBRERIA" ]; then
echo "Creando libreria $2.o ..."
gcc -c $2.c
fi

if [ "$1" = "EJECUTABLE_MAIN" ]; then
echo "Creando main $2 ..."
gcc -c $2.c
gcc -o $2 $2.c generacion.o
rm $2.o
fi

if [ "$1" = "EJECUTABLE_ASM" ]; then
echo "Creando objeto $2.o ..."
nasm -g -o $2.o -f elf32 $2.asm
echo "Enlazando para crear $2"
gcc -m32 -o $2 $2.o alfalib.o
echo "Eliminando el objeto $2.o ..."
rm $2.o
fi

if [ "$1" = "DESTRUIR" ]; then
echo "Destruyendo ejecutable $2"
rm $2
fi

