CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o

ejercicio4: lex.yy.c
	$(CC) $(CFLAGS) -o ejercicio4 ej_flex_4.c lex.yy.c

lex.yy.c: ej_flex_4.l
	flex ej_flex_4.l
