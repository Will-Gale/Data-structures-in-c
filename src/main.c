/****************************************
Main function, uses the data structures
 
 Devin Rose
 August, 2015
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT.h"
#include "binaryTree.h"

int main(int argc, const char * argv[]) {
    bool nodeCheck;
    char studentNameBuffer[50];
    const char * searchTestString;
    FILE * inputFile;
    Sinfo * searchTest;
    Sinfo * test;
    BinTree * binaryTree;
    void * searchVPtr;
    BinNode * searchResultsPtr;
    void * vPtr;
    
    if (argv[1] == NULL) {
        printf("Error: There is no data to enter, now exiting. \n");
        return 0;
    }
    
    inputFile = fopen(argv[1], "r");
    
    if (inputFile == NULL) {
        printf("Error: File could not be open, now exiting. /n");
        return 0;
    }
    
    
    printf("This function is being used to test and link the ADT and binary files together. \n");
    
    binaryTree = createBinaryTree(&compareName, &equalsADT, &destroyADT, &printADT);
    
    printf("Is node empty? ");
    
    nodeCheck = isNodeEmpty(binaryTree->root);
    
    if (nodeCheck == true) {
        printf("Yes. \n");
    } else if (nodeCheck == false) {
        printf("No \n");
    }
    
    /*now fill tree*/
    while (fgets(studentNameBuffer, 50, inputFile) != NULL) {
        test = createADT(studentNameBuffer);
        vPtr = test;

        binaryTree->root = addToBinaryTree(binaryTree, binaryTree->root, vPtr);
    }


    
    printf("Testing print in order \n");
    printInOrder(binaryTree, binaryTree->root);

    searchTestString = "Smith,718870";
    searchTest = createADT(searchTestString);
    searchVPtr = searchTest;

    printf("Testing equals for ");
    binaryTree->printFunction(binaryTree->root->binVPtr);
    printf(" and ");
    binaryTree->printFunction(searchVPtr);
    printf("\n");

    printf("Result = %d", equalsADT(binaryTree->root->binVPtr, searchVPtr));
    printf("\n");

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
    
    return 0;
}
