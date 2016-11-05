objFLAGS = -std=c11 -Wall -pedantic -ansi -g -Iinclude   -c -o

build:
	gcc $(objFLAGS) objLib/binTreeFunctions.o src/binTreeFunctions.c
	gcc $(objFLAGS) objLib/ADT.o src/ADT.c
	gcc $(objFLAGS) objLib/Stack.o src/Stack.c
	gcc $(objFLAGS) objLib/main.o src/main.c
	gcc objLib/main.o objLib/ADT.o objLib/binTreeFunctions.o objLib/Stack.o -o bin/runMe

test:
	valgrind -v --leak-check=yes --track-origins=yes bin/runMe docs/dataFile.txt

run:
	./bin/runMe docs/dataFile.txt
