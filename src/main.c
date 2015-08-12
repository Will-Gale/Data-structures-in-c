/****************************************
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

int main(int argc, const char * argv[])
{
    char studentNameBuffer[50];
    FILE * inputFile;
    Sinfo * test;
    BinTree * binaryTree;
    void * vPtr;
    
    if (argv[1] == NULL)
    {
        printf("Error: There is no data to enter, now exiting. \n");
        return 0;
    }
    
    inputFile = fopen(argv[1], "r");
    
    if (inputFile == NULL)
    {
        printf("Error: File could not be open, now exiting. /n");
        return 0;
    }
    
    
    printf("This function is being used to test and link the ADT and binary files together. \n");
    
    binaryTree = createBinaryTree(&compareName, &destroyADT);
    
    while (fgets(studentNameBuffer, 50, inputFile) != NULL)
    {
        test = createADT(studentNameBuffer);
        vPtr = test;
        
        printADT(vPtr);
        printf("\n");
        addToBinaryTree(binaryTree->compareFunction, binaryTree->root, vPtr);
    }
    
    
    return 0;
}
