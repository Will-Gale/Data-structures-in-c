CFLAGS = -std=c11 -Wall -pedantic -g -Iinclude -c
testBin = test/testExecutables

all:
	make build

binTreeFunctions.o:
	gcc $(CFLAGS) src/binTreeFunctions.c -o objLib/binTreeFunctions.o

ADT.o:
	gcc $(CFLAGS) src/ADT.c -o objLib/ADT.o

Stack.o:
	gcc $(CFLAGS) src/Stack.c -o objLib/Stack.o

main.o:
	gcc $(CFLAGS) src/main.c -o objLib/main.o

build: binTreeFunctions.o ADT.o Stack.o main.o
	gcc objLib/main.o objLib/ADT.o objLib/binTreeFunctions.o objLib/Stack.o -o bin/runMe
	make buildTest

buildTest:
	gcc $(CFLAGS) test/testing.c -o $(testBin)/testing.o
	gcc $(testBin)/testing.o -o $(testBin)/TestAll
	gcc $(CFLAGS) test/testingFunctions.c -o $(testBin)/testingFunctions.o
	gcc $(testBin)/testingFunctions.o objLib/ADT.o objLib/binTreeFunctions.o objLib/Stack.o -o $(testBin)/testIndividual

runTest:
	./$(testBin)/testAll


testMemoryLeak:
	valgrind -v --leak-check=yes --track-origins=yes bin/runMe docs/dataFile.txt


run:
	./bin/runMe docs/dataFile.txt
