CFLAGS = -std=c11 -Wall -pedantic -ansi -g -Iinclude -c -o
testBin = test/testExecutables

build:
	gcc $(CFLAGS) objLib/binTreeFunctions.o src/binTreeFunctions.c
	gcc $(CFLAGS) objLib/ADT.o src/ADT.c
	gcc $(CFLAGS) objLib/Stack.o src/Stack.c
	gcc $(CFLAGS) objLib/main.o src/main.c
	gcc objLib/main.o objLib/ADT.o objLib/binTreeFunctions.o objLib/Stack.o -o bin/runMe
	make buildTest

buildTest:
	gcc $(CFLAGS) $(testBin)/testing.o test/testing.c
	gcc $(testBin)/testing.o -o $(testBin)/TestAll
	gcc $(CFLAGS) $(testBin)/testingFunctions.o test/testingFunctions.c
	gcc $(testBin)/testingFunctions.o objLib/ADT.o objLib/binTreeFunctions.o objLib/Stack.o -o $(testBin)/testIndividual

runTest:
	./$(testBin)/testAll


testMemoryLeak:
	valgrind -v --leak-check=yes --track-origins=yes bin/runMe docs/dataFile.txt


run:
	./bin/runMe docs/dataFile.txt
