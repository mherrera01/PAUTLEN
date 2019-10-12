#!/bin/sh

if [ "$1" = "CREAR" ]; then
echo "Creando objeto $2.o ..."
nasm -g -o $2.o -f elf32 $2.asm
echo "Enlazando para crear $2"
gcc -m32 -o $2 $2.o alfalib.o
fi

if [ "$1" = "DESTRUIR" ]; then
echo "Destruyendo objeto $2.o"
rm $2.o
echo "Destruyendo ejecutable $2"
rm $2
fi

