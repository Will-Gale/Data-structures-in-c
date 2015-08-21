/****************************************
ADT Binary tree user interface
 
 Devin Rose
 August, 2015
****************************************/

#include<stdio.h>
#include<stdlib.h>

/*Created boolean data type*/
typedef int bool;
enum {false, true};

/*************************************
 Required variables for Binary Tree
 *************************************/

/*Typedefs of the ADTs used. All typedefs have the first letter capitalized*/
typedef struct binaryTree BinTree;
typedef struct binaryElement BinNode;

/*data type to create the Binary tree*/
struct binaryTree
{
    int (*compareFunction) (void * data1, void * data2);
    void (* destroyFunction) (void * data);
    BinNode * root;
};

/*Required variables in a binary tree node*/
struct binaryElement
{
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
 
 To call the function you must pass the comparison and destroy functions you will use to sort and free the data in the binary tree. Using function pointers and sending the address of the functions allows the program to access the data whenever required from the compare function.
 
 The comparison function must return a number > 0 if data1 > data2, 0 if data1 = data2, and < 0 if data1 < data2.
 
 Example call: createBinaryTree(&compareFunction, &destroyFunction)
****************************************/
BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), void (* destroyPtr) (void * data));

/*destroyBinaryTree()*/

/****************************************
Inserts a child node into the binary tree. Memory is malloced in this function for new elements.
 ****************************************/
BinNode * insertNode(void * toAdd);

/*void removeFromTree()*/

/*binNode * searchBinTree()*/

/*Tree * getLeftChildNode*/

/*Tree * getRightChildNode*/

/*void * getRootData(Tree *)*/

/*void printInOrder(Tree * theTree)*/

/*void printPreOrder(Tree * theTree, void (* printNode) (void data))*/

/*void printBinaryTree(Tree *)*/

/****************************************
 Checks to see if the node is empty.
 
 Returns true if the node is NULL, returns false otherwise.
 ****************************************/
bool isNodeEmpty(BinNode * root);

/*bool isTreeEmpty(Tree * theTree)*/
 
