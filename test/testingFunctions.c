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
        printf("Test number = %s \n", argv[2]);
        /* Regression testing */
        if (strcmp(argv[2], "0") == 0) {
            TEST_BinaryTree(inputFile);
        } else if (strcmp(argv[2], "1") == 0) {
            TEST_Stack(inputFile);
        }
    }
    
    return 0;
}




/******
 Individual Testing functions
 ******/



/* Simple function for testing the binary tree */
void TEST_BinaryTree(FILE * inputStream) {
    const char * searchTestString;
    char studentNameBuffer[50];
    Sinfo * searchTest;
    Sinfo * testBin;
    Sinfo * testAvl;
    BinTree * binaryTree;
    void * searchVPtr;
    BinNode * searchResultsPtr;
    void * vPtrBin;
    void * vPtrAvl;
    
    binaryTree = createBinaryTree(&compareName, &equalsADT, &destroyADT, &printADT);
    
    /* Fill tree */
    while (fgets(studentNameBuffer, 50, inputStream) != NULL) {
        testBin = createADT(studentNameBuffer);
        testAvl = createADT(studentNameBuffer);
        vPtrBin = testBin;
        vPtrAvl = testAvl;
        
        binaryTree->root = addToBinaryTree(binaryTree, binaryTree->root, vPtrBin);
    }
    
    printf("Testing print in order \n");
    printInOrder(binaryTree, binaryTree->root);
    
    searchTestString = "Smith,718870";
    searchTest = createADT(searchTestString);
    searchVPtr = searchTest;
    
    printf("Testing search for ");
    binaryTree->printFunction(searchVPtr);
    printf("\n");
    searchResultsPtr = searchBinTree(binaryTree, binaryTree->root, searchVPtr);
    
    if (searchResultsPtr != NULL) {
        printf("Found: ");
        binaryTree->printFunction(searchResultsPtr->binVPtr);
        printf("\n");
    } else if (searchResultsPtr == NULL) {
        binaryTree->printFunction(searchVPtr);
        printf(" was not found\n");
    }
    
    destroyBinaryTree(binaryTree, binaryTree->root);
}




/* Simple function for testing the binary tree */
void TEST_Stack(FILE * inputStream) {
    char studentNameBuffer[50];
    Sinfo * testNode;
    void * vPtr;

    /* Create stack */
    Stack * testStack = newStack(&destroyADT, &printADT);

    /* Fill Stack */
    while (fgets(studentNameBuffer, 50, inputStream) != NULL) {
        testNode = createADT(studentNameBuffer);

        vPtr = testNode;
        printf("Now adding the following node,\n\t");
        testStack->push(testStack, vPtr);
        testStack->toString(testStack->root->dataInNode);
        printf("\n\t listSize = %d\n", testStack->stackSize);
    }

    /* Pop off all nodes and print each node that is removed*/
    while(testStack->root != NULL) {
        printf("Now removing and freeing the following node,\n\t");
        testStack->toString(testStack->root->dataInNode);
        testStack->pop(testStack);
        printf("\n\t listSize = %d\n", testStack->stackSize);
    }
    
    testStack->pop(testStack); /* Attempting to remove a node from an empty stack */

    free(testStack);
}


