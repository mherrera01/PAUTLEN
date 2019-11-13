CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o

ejercicio3: lex.yy.c
	$(CC) $(CFLAGS) -o ejercicio3 ej_flex_3.c lex.yy.c

lex.yy.c: ej_flex_3.l
	flex ej_flex_3.l
