all: PruebaSemantico GenerarAsm

lex.yy.c: src/alfa.l y.tab.h
	flex src/alfa.l

y.tab.c: src/alfa.y
	bison -d -y -v 	src/alfa.y

PruebaSemantico: y.tab.c lex.yy.c src/main.c
	gcc -c src/main.c
	gcc -c lex.yy.c y.tab.c src/main.c src/generacion.c src/tablaSimbolos.c src/tablaHash.c
	gcc -o alfa lex.yy.o y.tab.o main.o generacion.o tablaSimbolos.o tablaHash.o

GenerarAsm: alfa
	./alfa prg1.alf prg1.asm

CompilarAsm:
	nasm -felf32 prg1.asm

CompilarEjecutable:
	gcc -m32 -o prg1 prg1.o obj/alfalib.o

clean:
	rm -rf *.h.gch y.tab.c y.tab.h y.output lex.yy.c alfa prg1 *.o
