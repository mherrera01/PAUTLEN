CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o



ejercicio1: lex.yy.c
	$(CC) $(CFLAGS) -o ejercicio1 ej_flex_1.c lex.yy.c

lex.yy.c: ej_flex_1.l
	flex ej_flex_1.l
