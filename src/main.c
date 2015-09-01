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
    bool nodeCheck;
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
    
    printf("Is node empty? ");
    
    nodeCheck = isNodeEmpty(binaryTree->root);
    
    if (nodeCheck == true)
    {
        printf("Yes. \n");
    }
    else if (nodeCheck == false)
    {
        printf("No \n");
    }
    
    while (fgets(studentNameBuffer, 50, inputFile) != NULL)
    {
        test = createADT(studentNameBuffer);
        vPtr = test;
        
        binaryTree->root = addToBinaryTree(binaryTree, binaryTree->root, vPtr);
        printADT(binaryTree->root->binVPtr);
        printf("\n");
    }
    
    destroyBinaryTree(binaryTree, binaryTree->root);
    
    return 0;
}
