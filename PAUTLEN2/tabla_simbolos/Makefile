CC = gcc -ansi -pedantic
CFLAGS = -Wall -g
OBJ = *.o
OBJGCH = *.h.gch


all: prueba_tabla.o
	gcc -o prueba_tabla prueba_tabla.o tablaSimbolos.o tablaHash.o

prueba_tabla.o:	tablaSimbolos.o
	gcc -c prueba_tabla.c tablaSimbolos.h

tablaSimbolos.o: tablaHash.o
	gcc -c tablaSimbolos.c  tablaHash.h

tablaHash.o:
	gcc -c tablaHash.c tablaHash.h

clean:
	rm -rf prueba_tabla  $(OBJ) $(OBJGCH)