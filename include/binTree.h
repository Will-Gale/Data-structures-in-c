/****************************************
ADT Binary tree user interface
 
 Devin Rose
 August, 2015
****************************************/

#include <stdio.h>
#include <stdlib.h>

/*Created boolean data type*/
typedef int boolBin;
enum {false, true};

/*************************************
 Required variables for Binary Tree
 *************************************/

/*Typedefs of the ADTs used. All typedefs have the first letter capitalized*/
typedef struct binaryTree BinTree;
typedef struct binaryElement BinNode;

/*data type to create the Binary tree*/
struct binaryTree {
    int (*compareFunction) (void * data1, void * data2);
    int (*equalsFunction) (void * data1, void * data2);
    void (* destroyFunction) (void * data);
    char * (* toString) (void * dataToString);
    BinNode * root;
};

/*Required variables in a binary tree node*/
struct binaryElement {
    void * binVPtr;
    BinNode * leftNode;
    BinNode * rightNode;
};

/****************************************
 Uses the compare function to add data to a binary tree from a void pointer.
 
 This function traverses through the tree using recursion.
 
 Example call: addToBinaryTree(&compareFunction, dataToAdd)
 ****************************************/
BinNode * addToBinaryTree(BinTree * theTree, BinNode * root, void * dataToAdd);


/****************************************
 Allocates enough memory to store the required data for a binary tree, and initializes the tree.
 
 To call the function you must pass comparison, print and destroy functions that you will use to 
 sort and free the data in the binary tree. Using function pointers and sending the address of 
 the functions allows the program to access the data whenever required from the compare function.
 
 The comparison function must return a number > 0 if data1 > data2, 0 if data1 = data2, 
 and < 0 if data1 < data2.
 
 Example call: createBinaryTree(&compareFunction, &destroyFunction, &printFunction);
****************************************/
BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), int (*equalsFunction) (void * data1, void * data2), void (* destroyPtr) (void * data), char * (* toStringPtr) (void * dataToPrint));


/****************************************
 This function is called when you would like to free all memory allocated in the binary tree.
 
 Recursive function that traverses through the tree destroying from the lowest valued node, to 
 the highest.
 
 DO NOT CALL THIS FUNCTION if you would like to free all memory using the destroyBinaryTree() 
 function. The destroyBinaryTree() function already calls this function before freeing the 
 elements within the tree data structure.
 ****************************************/
void destroyBinaryTree(BinTree * treeToFree, BinNode * currentNode);


/****************************************
 This function destroys a node in the binary tree. It takes the tree as an argument and the 
 node and frees all memory allocated in the node and frees the data being pointed to from 
 the ADT used.
 
 The tree must be initialized and contain the users destroy function for whatever data type 
 they are choosing to use.
 
 This function simply frees the memory. If the user wants to simply remove the node, use 
 removeNodeFromBinTree() function. This function will cause a segmentation fault or lost 
 data somewhere in the tree if the user calls this function instead of removeFromBinTree()
 ****************************************/
void destroyBinaryNode(BinTree * treeToFree, BinNode * nodeToFree);


/****************************************
Inserts a child node into the binary tree. Memory is malloced in this function for new 
elements.
 ****************************************/
BinNode * insertNode(void * toAdd);


/****************************************
 This function function fully removes a node from the tree and frees the memory allocated in 
 the node.
 
 Write the plan when decision has been made.
 ****************************************/
/*void removeNodeFromBinTree(BinTree * theTree, BinNode->nodeToRemove);*/

/****************************************
 Traverses through the binary tree and returns a pointer to the node if the search finds a 
 mathcing node.

 Returns null if the node is not found. 
 ****************************************/
BinNode * searchBinTree(BinTree * toSearch, BinNode * nodeInTree, void * ptrToFind);

/*Tree * getLeftChildNode*/

/*Tree * getRightChildNode*/

/*void * getRootData(Tree *)*/

/*void printBinaryTree(Tree *)*/

/****************************************
 Checks to see if the node is empty.
 
 Returns true if the node is NULL, returns false otherwise.
 ****************************************/
boolBin isNodeEmpty(BinNode * root);

/*bool isTreeEmpty(Tree * theTree)*/

/****************************************
 Calling this function will print the binary tree elements in order from least to most by traversing 
 through the tree left then right.
 ****************************************/
void printInOrder(BinTree * theTree, BinNode * nodeToPrint);
 
void writeInOrder(BinTree * theTree, BinNode * nodeToPrint, FILE * stream);

