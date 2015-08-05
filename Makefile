objFLAGS = -Wall -pedantic -ansi -g -Iinclude   -c -o

all:
	gcc $(objFLAGS) objLib/binTreeFunctions.o src/binTreeFunctions.c
	gcc $(objFLAGS) objLib/ADT.o src/ADT.c
	gcc $(objFLAGS) objLib/main.o src/main.c
	gcc objLib/main.o objLib/ADT.o objLib/binTreeFunctions.o -o bin/runMe

run:
	./bin/runMe docs/dataFile.txt
