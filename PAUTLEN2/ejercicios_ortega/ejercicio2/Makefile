CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o

ejercicio2: lex.yy.c
	$(CC) $(CFLAGS) -o ejercicio2 ej_flex_2.c lex.yy.c

lex.yy.c: ej_flex_2.l
	flex ej_flex_2.l
