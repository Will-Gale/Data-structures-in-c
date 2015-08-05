/****************************************
 Main function
 
 Devin Rose
 August, 2015
 ****************************************/

#include "binaryTree.h"

BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), void (* destroyPtr) (void * data))
{
    BinTree * newBinaryTree;
    
    /*allocate enough memory for a binary tree*/
    newBinaryTree = malloc(sizeof(BinTree));
    
    /*initialize variables*/
    newBinaryTree->compareFunction = comparePtr;
    newBinaryTree->destroyFunction = destroyPtr;
    newBinaryTree->root = NULL;
    
    /*return the newly initialized binary tree*/
    return newBinaryTree;
}
