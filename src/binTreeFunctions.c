/****************************************
 Main function
 
 Devin Rose
 August, 2015
 ****************************************/

#include "binTree.h"

/* Finds where to added to the binary tree */
BinNode * addToBinaryTree(BinTree * theTree, BinNode * root, void * dataToAdd) {
    if (isNodeEmpty(root) == true) {
        /* Allocate enough memory and insert to root when the node is empty */
        root = insertNode(dataToAdd);
    } else {
        if (theTree->compareFunction(dataToAdd, root->binVPtr) < 0) {
            root->leftNode = addToBinaryTree(theTree, root->leftNode, dataToAdd); /* Traverse left */
        } else if (theTree->compareFunction(dataToAdd, root->binVPtr) >= 0) {
            root->rightNode = addToBinaryTree(theTree, root->rightNode, dataToAdd); /* Traverse right */
        } else {
            printf("Error: Node could not be added to the tree \n");
        }
    }
    
    return root;
}

/* Initializes the binary tree */
BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), int (*equalsFunction) (void * data1, void * data2), void (* destroyPtr) (void * data), char * (* toStringPtr) (void * dataToPrint)) {
    BinTree * newBinaryTree;
    
    /*allocate enough memory for a binary tree*/
    newBinaryTree = malloc(sizeof(BinTree));
    /*newBinaryTree->root = malloc(sizeof(BinNode));*/
    
    /*initialize variables*/
    newBinaryTree->compareFunction = comparePtr;
    newBinaryTree->equalsFunction = equalsFunction;
    newBinaryTree->destroyFunction = destroyPtr;
    newBinaryTree->toString = toStringPtr;
    newBinaryTree->root = NULL;
    
    /*return the newly initialized binary tree*/
    return newBinaryTree;
}


/* Free memory allocated in a node in the tree */
void destroyBinaryNode(BinTree * theTree, BinNode * nodeToFree) {
    if(nodeToFree != NULL) {
        theTree->destroyFunction(nodeToFree->binVPtr);
        nodeToFree->binVPtr = NULL;
        
        /* Frees memory allocated in the nodeToFree */
        free(nodeToFree->leftNode);
        free(nodeToFree->rightNode);

        nodeToFree->leftNode = NULL;
        nodeToFree->rightNode = NULL;
    }
}


/* Frees all memory allocated within the binary tree nodes from lowest valued to highest valued node */
void destroyBinaryTree(BinTree * treeToFree, BinNode * currentNode) {
    /*This if statement prevents seg faults when destroying an already empty tree*/
    if(treeToFree == NULL || currentNode == NULL) { /* The root of the tree is NULL */
        return;
    }

    /*Traverse left*/
    if (currentNode->leftNode != NULL) {
        destroyBinaryTree(treeToFree, currentNode->leftNode);
    }
    
    /*traverse right*/
    if (currentNode->rightNode != NULL) {
        destroyBinaryTree(treeToFree, currentNode->rightNode);
    }
    
    /* Frees the memory of the node if both child nodes are NULL, the sets the current node to null */

    destroyBinaryNode(treeToFree, currentNode);
    currentNode = NULL;
}

/* Allocates enough memory and fills a new node */
BinNode * insertNode(void * toAdd) {
    BinNode * newNode;
    
    /*Allocate enough memory and insert to root when the node is empty*/
    newNode = malloc(sizeof(BinNode));
    newNode->binVPtr = toAdd;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    
    return newNode;
}

/* Checks to see if the node is empty */
boolBin isNodeEmpty(BinNode * root) {

    if (root == NULL) {
        return true;
    } else if (root != NULL && root->binVPtr != NULL) {
        return false;
    } else {
        printf("Error: An error occured while checking if a node was empty, making an assumption that node is empty. Data may be lost. \n");
        return true;
    }
}

/* Prints the list of nodes in the tree in order */
void printInOrder(BinTree * theTree, BinNode * nodeToPrint) {
    /* Wrapper function to call write in order to print to command line */
    writeInOrder(theTree, nodeToPrint, stdout);
}

void writeInOrder(BinTree * theTree, BinNode * nodeToPrint, FILE * stream) {
    if (nodeToPrint->leftNode != NULL) {
        writeInOrder(theTree, nodeToPrint->leftNode, stream);
    }

    if (nodeToPrint !=  NULL) {
        fprintf(stream, "%s\n", theTree->toString(nodeToPrint->binVPtr));
    }
    
    if (nodeToPrint->rightNode != NULL) {
        writeInOrder(theTree, nodeToPrint->rightNode, stream);
    }
}

/* Searches the tree and returns a matching node if found, if not found, returns null */
BinNode * searchBinTree(BinTree * toSearch, BinNode * nodeInTree, void * ptrToFind) {
    BinNode * nodePtr = NULL;

    if (ptrToFind == NULL) {
        return NULL;
    }

    if (isNodeEmpty(nodeInTree) == false) {
        if (toSearch->compareFunction(ptrToFind, nodeInTree->binVPtr) == 0) {
            if (toSearch->equalsFunction(nodeInTree->binVPtr, ptrToFind) == 1) { /*Check equals*/
                nodePtr = nodeInTree;
                return nodePtr; /*Return the pointer to end the recursive calls*/
            } 
        }

        if (toSearch->compareFunction(ptrToFind, nodeInTree->binVPtr) >= 0) {
            nodePtr = searchBinTree(toSearch, nodeInTree->rightNode, ptrToFind); /* Traverse right */
        } else if (toSearch->compareFunction(ptrToFind, nodeInTree->binVPtr) < 0) {
            nodePtr = searchBinTree(toSearch, nodeInTree->leftNode, ptrToFind); /* Traverse left */
        }
    } else {
        nodePtr = nodeInTree;
    }

    return nodePtr;
}






