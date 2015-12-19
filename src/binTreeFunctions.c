/****************************************
 Main function
 
 Devin Rose
 August, 2015
 ****************************************/

#include "binaryTree.h"

/*finds where to added to the binary tree*/
BinNode * addToBinaryTree(BinTree * theTree, BinNode * root, void * dataToAdd) {
    if (isNodeEmpty(root) == true) {
        /*Allocate enough memory and insert to root when the node is empty*/
        root = insertNode(dataToAdd);
    } else {
        if (theTree->compareFunction(dataToAdd, root->binVPtr) < 0) {
            root->leftNode = addToBinaryTree(theTree, root->leftNode, dataToAdd); /*Traverse left*/
        } else if (theTree->compareFunction(dataToAdd, root->binVPtr) >= 0) {
            root->rightNode = addToBinaryTree(theTree, root->rightNode, dataToAdd); /*Traverse right*/
        } else {
            printf("Error: Node could not be added to the tree \n");
        }
    }
    
    return root;
}

/*Initializes the binary tree.*/
BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), void (* destroyPtr) (void * data), void (* printPtr) (void * dataToPrint)) {
    BinTree * newBinaryTree;
    
    /*allocate enough memory for a binary tree*/
    newBinaryTree = malloc(sizeof(BinTree));
    newBinaryTree->root = malloc(sizeof(BinNode));
    
    /*initialize variables*/
    newBinaryTree->compareFunction = comparePtr;
    newBinaryTree->destroyFunction = destroyPtr;
    newBinaryTree->printFunction = printPtr;
    newBinaryTree->root = NULL;
    
    /*return the newly initialized binary tree*/
    return newBinaryTree;
}

/*Free memory allocated in a node in the tree*/
void destroyBinaryNode(BinTree * theTree, BinNode * nodeToFree) {
    theTree->destroyFunction(nodeToFree->binVPtr);
    
    free(nodeToFree->leftNode);
    free(nodeToFree->rightNode);
}


/*Frees all memory allocated within the binary tree nodes from lowest valued to highest valued node*/
void destroyBinaryTree(BinTree * treeToFree, BinNode * currentNode) {
    /*Traverse left*/
    if (currentNode->leftNode != NULL) {
        destroyBinaryTree(treeToFree, currentNode->leftNode);
    }
    
    /*traverse right*/
    if (currentNode->rightNode != NULL) {
        destroyBinaryTree(treeToFree, currentNode->rightNode);
    }
    
    /*frees the memory of the node if both child nodes are NULL*/
    destroyBinaryNode(treeToFree, currentNode);
    currentNode = NULL;
}

/*Allocates enough memory and fills a new node*/
BinNode * insertNode(void * toAdd) {
    BinNode * newNode;
    
    /*Allocate enough memory and insert to root when the node is empty*/
    newNode = malloc(sizeof(BinNode));
    newNode->binVPtr = toAdd;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    
    return newNode;
}

/*checks to see if the node is empty*/
bool isNodeEmpty(BinNode * root) {
    if (root == NULL) {
        return true;
    } else if (root != NULL) {
        return false;
    } else {
        printf("Error: An error occured while checking if a node was empty, making an assumption that node is empty. Data may be lost. \n");
        return true;
    }
}

/*Not 100% correct*/
void printInOrder(BinTree * theTree, BinNode * nodeToPrint) {
    if (nodeToPrint->leftNode != NULL) {
        printInOrder(theTree, nodeToPrint->leftNode);
    }

    if (nodeToPrint !=NULL) {
        theTree->printFunction(nodeToPrint->binVPtr);
        printf("\n");
    }
    
    if (nodeToPrint->rightNode != NULL) {
        printInOrder(theTree, nodeToPrint->rightNode);
    }
    
}

