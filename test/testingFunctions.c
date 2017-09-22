/****************************************
 Individual testing functions, reports any failed unit tests.
 
 DevRows
 September, 2017
 ****************************************/


/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Individual libraries that are tested */
#include "ADT.h"
#include "avlTree.h"
#include "binTree.h"
#include "Stack.h"



/******
 Function prototypes for testing the varrious data structures.
 ******/

/* Binary Tree */
void TEST_BinaryTree(FILE * inputStream);

/* Stack */
void TEST_Stack(FILE * inputStream);



/******
 Miscellaneous functions useful for unit tests.

    Returns 1 if they're equivalent, 0 if different.
 ******/

int compareFile(char * fileNameOne, char * fileNameTwo);

/*void writeFile(void * dataToWrite, char * fileName);*/

int binaryTreeSearchTest(BinTree * binaryTree);

int binaryTreeSortTest(BinTree * binaryTree);



int main(int argc, const char * argv[]) {
    FILE * inputFile;

    /* No command line argument */
    if (argv[1] == NULL) {
        printf("Error: There is no data to enter, now exiting. \n");
        return 0;
    }
    
    inputFile = fopen(argv[1], "r");
    
    if (inputFile == NULL) {
        /* No file was found */
        printf("Error: File could not be open, now exiting. /n");
    } else {
        printf("Testing suite = %s \n", argv[2]);

        /* Regression testing */
        if (strcmp(argv[2], "0") == 0) {
            TEST_BinaryTree(inputFile);
        } else if (strcmp(argv[2], "1") == 0) {
            TEST_Stack(inputFile);
        }
    }
    
    fclose(inputFile);

    return 0;
}



/******
 Miscellaneous helper functions
 ******/

int compareFile(char * fileNameOne, char * fileNameTwo) {
    char buffOne[100];
    char buffTwo[100];
    int flag = 1;
    FILE * fileOne;
    FILE * fileTwo;

    /* Open files */
    fileOne = fopen(fileNameOne, "r");
    fileTwo = fopen(fileNameTwo, "r");

    /* Read and compare all lines of the text file */
    while (fgets(buffOne, 100, fileOne) != NULL && fgets(buffTwo, 100, fileTwo) != NULL && flag == 1) {
        if (strcmp(buffOne, buffTwo) != 0) {
            flag = 0;
        }
    }

    /* Close stream to the files compared */
    fclose(fileOne);
    fclose(fileTwo);

    return flag;
}


int individualSearchResults(void * ptr) {
    if (ptr != NULL) {
        /*fprintf(stdout, "Found: %s\n", binaryTree->toString(searchResultsPtr->binVPtr));*/
        return 1;
    } else if (ptr == NULL) {
        return 0;
    } 

    return 0;
}

/* Testing search functionality
Unit tests:
    0 -> Search empty tree

    1 -> Search with empty node
    2 -> Search with NULL pointer

    3 -> Search for root node
    4 -> Search on left side
    5 -> Search on right side
    6 -> Search not in tree 
    7 -> Search bottom of the tree*/
int binaryTreeSearchTest(BinTree * binaryTree) {
    BinNode * searchResultsPtr;
    BinTree * emptyTree;
    char * searchStrings[5];
    int i;
    int finalResult = 1;
    int results[8];
    int expectedResults[8];
    Sinfo * searchTest;
    void * searchVPtr;

    /* Expected search results, 0 = not found, 1 = found in tree */
    expectedResults[0] = 0;
    expectedResults[1] = 0;
    expectedResults[2] = 0;
    expectedResults[3] = 1;
    expectedResults[4] = 1;
    expectedResults[5] = 1;
    expectedResults[6] = 0;
    expectedResults[7] = 1;

    /* Individual search strings for unit tests 4 -> 8 */
    searchStrings[0] = "Karl,985610";
    searchStrings[1] = "Chewy,981234";
    searchStrings[2] = "Smith,718870";
    searchStrings[3] = "notInList,943937";
    searchStrings[4] = "Albert,984416";

    /*0: Search empty tree*/
    emptyTree = createBinaryTree(&compareName, &equalsADT, &destroyADT, &toString);
    searchTest = createADT("Karl,985610");
    searchVPtr = searchTest;
    searchResultsPtr = searchBinTree(emptyTree, emptyTree->root, searchVPtr);
    destroyADT(searchVPtr);
    destroyBinaryTree(emptyTree, emptyTree->root);

    if (searchResultsPtr == NULL) {
        results[0] = 0;
    } else {
        results[0] = 1;
    }

    /* 1: Search with empty node */
    searchTest = createADT(NULL);
    searchVPtr = searchTest;
    searchResultsPtr = searchBinTree(binaryTree, binaryTree->root, searchVPtr);
    destroyADT(searchVPtr);

    if (searchResultsPtr == NULL) {
        results[1] = 0;
    } else {
        results[1] = 1;
    }
    
    /* 2: Search with NULL pointer */
    searchResultsPtr = searchBinTree(binaryTree, binaryTree->root, searchVPtr);

    if (searchResultsPtr == NULL) {
        results[2] = 0;
    } else {
        results[2] = 1;
    }

    /* 3-7: Test case searches */
    for(i = 0; i < 5; i++) {
        searchTest = createADT(searchStrings[i]);
        searchVPtr = searchTest;
        searchResultsPtr = searchBinTree(binaryTree, binaryTree->root, searchVPtr);

        if (searchResultsPtr == NULL) {
            results[i+3] = 0;
        } else {
            results[i+3] = 1;
        }

        destroyADT(searchVPtr);
    }

    /* Compare results with expected results */
    for(i = 0; i < 8; i++) {
        if(results[i] != expectedResults[i]) {
            printf("FAILED: binary search test # %d\n", i);
            finalResult = 0;
        }
    }

    return finalResult;
}


int binaryTreeSortTest(BinTree * binaryTree) {
    FILE * sortFile;

    /* Opens a stream and prints writes to the file */
    sortFile = fopen("test/sortTest.txt", "w");
    writeInOrder(binaryTree, binaryTree->root, sortFile);

    fclose(sortFile);

    return compareFile("test/sortTest.txt", "test/inOrder.txt");
}



/******
 Individual Testing functions
 ******/



/* Simple function for testing the binary tree */
void TEST_BinaryTree(FILE * inputStream) {
    char studentNameBuffer[100];
    const char * result[2];
    int testResult;  
    BinTree * binaryTree;
    Sinfo * testBin;
    void * vPtrBin;
    
    /* Results array */
    result[0] = "FAILED";
    result[1] = "PASSED";

    binaryTree = createBinaryTree(&compareName, &equalsADT, &destroyADT, &toString);
    
    /* Fill tree: required before we test anything */
    while (fgets(studentNameBuffer, 100, inputStream) != NULL) {
        testBin = createADT(studentNameBuffer);
        vPtrBin = testBin;
        
        binaryTree->root = addToBinaryTree(binaryTree, binaryTree->root, vPtrBin);
    }
    

    /* Testing sort functionality */
    testResult = binaryTreeSortTest(binaryTree);
    printf("\t%s: Binary tree sort test (test set 1 of 3)\n", result[testResult]);


    /* Testing add NULL student */
    testResult = binaryTreeSearchTest(binaryTree);
    printf("\t%s: Binary tree search test (test set 2 of 3)\n", result[testResult]);


    /* Testing free memory allocation functionality */
    destroyBinaryTree(binaryTree, NULL);
    destroyBinaryTree(binaryTree, binaryTree->root);
    destroyBinaryTree(binaryTree, NULL);
    printf("\t%s: Double destroy binary tree (test set 3 of 3)\n", result[testResult]);
}




/* Simple function for testing the binary tree */
void TEST_Stack(FILE * inputStream) {
    char studentNameBuffer[100];
    Sinfo * testNode;
    void * vPtr;

    /* Create stack */
    Stack * testStack = newStack(&destroyADT, &printADT, &writeADT, &toString);

    /* Fill Stack */
    while (fgets(studentNameBuffer, 100, inputStream) != NULL) {
        testNode = createADT(studentNameBuffer);

        vPtr = testNode;
        printf("Now adding the following node,\n\t");
        testStack->push(testStack, vPtr);
        testStack->print(testStack->root->dataInNode);
        printf("\n\t listSize = %d\n", testStack->stackSize);
    }

    /* Pop off all nodes and print each node that is removed*/
    while(testStack->root != NULL) {
        printf("Now removing and freeing the following node,\n\t");
        testStack->print(testStack->root->dataInNode);
        testStack->pop(testStack);
        printf("\n\t listSize = %d\n", testStack->stackSize);
    }
    
    testStack->pop(testStack); /* Attempting to remove a node from an empty stack */

    free(testStack);
}


