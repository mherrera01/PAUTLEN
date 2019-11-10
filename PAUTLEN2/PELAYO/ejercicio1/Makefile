CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o


all: lex.yy.o
	$(CC) $(CFLAGS) -o ejercicio1 lex.yy.o 
lex.yy.o: lex.yy.c tokens.h
	$(CC) $(CFLAGS) -c lex.yy.c
lex.yy.c: ej_flex_1.l
	flex ej_flex_1.l
