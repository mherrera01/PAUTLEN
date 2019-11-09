CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o


all: lex.yy.o
	$(CC) $(CFLAGS) -o pruebaMorfo lex.yy.o
lex.yy.o: lex.yy.c tokens.h
	$(CC) $(CFLAGS) -c lex.yy.c
lex.yy.c: alfa.l
	flex alfa.l
clean:
	rm -rf pruebaMorfo  $(OBJ) lex.yy.c