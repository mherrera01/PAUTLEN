all: PruebaSemantico GenerarAsm CompilarAsm CompilarEjecutable

lex.yy.c: alfa.l y.tab.h
	flex alfa.l

y.tab.c: alfa.y
	bison -d -y -v alfa.y

PruebaSemantico: y.tab.c lex.yy.c main.c
	gcc -c main.c
	gcc -c lex.yy.c y.tab.c main.c generacion.c tablaSimbolos.c tablaHash.c
	gcc -o alfa lex.yy.o y.tab.o main.o generacion.o tablaSimbolos.o tablaHash.o

GenerarAsm: alfa
	./alfa prg1.alf prg1.asm

CompilarAsm:
	nasm -felf32 prg1.asm

CompilarEjecutable:
	gcc -m32 -o prg1 prg1.o alfalib.o

clean:
	rm -rf *.h.gch y.tab.c y.tab.h y.output lex.yy.c alfa prg1
