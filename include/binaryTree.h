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
/*data type to create the Binary tree*/
struct binaryTree
{
    int (*compareFunction) (void * data1, void * data2);
    void (* destroyFunction) (void * data);
    struct binaryTree * root;
};
typedef struct binaryTree BinTree;

/*Required variables in a binary tree node*/
struct binaryElement
{
    void * binVPtr;
    struct binaryElement * leftNode;
    struct binaryElement * rightNode;
};
typedef struct binElement BinNode;

/****************************************
 Allocates enough memory to store the required data for a binary tree, and initializes the tree.
 
 To call the function you must pass the comparison and destroy functions you will use to sort and free the data in the binary tree. Using function pointers and sending the address of the functions allows the program to access the data whenever required from the compare function.
 
 Example call: createBinaryTree(&compareFunction, &destroyFunction)
****************************************/
BinTree * createBinaryTree(int (*comparePtr) (void * data1, void * data2), void (* destroyPtr) (void * data));

/*destroyBinaryTree()*/

/*void addToTree()*/

/*void removeFromTree()*/

/*binNode * searchBinTree()*/

/*Tree * getLeftChildNode*/

/*Tree * getRightChildNode*/

/*void * getRootData(Tree *)*/

/*void printInOrder(Tree * theTree)*/

/*void printPreOrder(Tree * theTree, void (* printNode) (void data))*/

/*void printBinaryTree(Tree *)*/

/*bool isTreeEmpty(Tree * theTree)*/
 
