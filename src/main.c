/****************************************
Main function, uses the data structures
 
 Devin Rose
 August, 2015
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Imported data types */
#include "ADT.h"
#include "avlTree.h"
#include "binTree.h"
#include "Stack.h"


/******
 Function prototypes of the various structures and how they can be used.
 ******/

/* Binary Tree */
void testBinaryTree(FILE * inputStream);

/* Stack */
void testStack(FILE * inputStream);



/* 
 Main function for calling tests 
 */
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
        /* Call testing function */
        /*testBinaryTree(inputFile);*/
        testStack(inputFile);
    }
    
    return 0;
}


/******
 Testing functions
 ******/


/* Simple function for testing the binary tree */
void testBinaryTree(FILE * inputStream) {
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
    
    printf("This function is being used to test and link the ADT and binary files together. \n");
    
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
void testStack(FILE * inputStream) {
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
        printf("\n\t listSize = %d\n", testStack->size);
    }

    /* Pop off all nodes and print each node that is removed*/
    while(testStack->root != NULL) {
        printf("Now removing and freeing the following node,\n\t");
        testStack->toString(testStack->root->dataInNode);
        testStack->pop(testStack);
        printf("\n");
    }

    free(testStack);
}

