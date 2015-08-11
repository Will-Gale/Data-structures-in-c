/****************************************
 Main function
 
 Devin Rose
 August, 2015
 ****************************************/

#include "binaryTree.h"

/*Initializes the binary tree.*/
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

/*Not tested yet*/
/*finds where to added to the binary tree*/
void addToBinaryTree(int (*comparePtr) (void * data1, void * data2), BinNode * root, void * dataToAdd)
{
    if (isNodeEmpty(root) == false)
    {
        /*Traverse left*/
        if (comparePtr(root->binVPtr, dataToAdd) < 0)
        {
            addToBinaryTree(comparePtr, root->leftNode, dataToAdd);
        }
        
        /*Traverse right*/
        if (comparePtr(root->binVPtr, dataToAdd) >= 0)
        {
            addToBinaryTree(comparePtr, root->rightNode, dataToAdd);
        }
    }
    else
    {
        /*insert to root*/
    }
}

/*Not tested yet*/
/*checks to see if the node is empty*/
bool isNodeEmpty(BinNode * root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

