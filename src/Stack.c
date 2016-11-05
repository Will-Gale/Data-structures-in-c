/****************************************
 Functions for creating and using a Stack.
 
 Stack.h
 
 devrows
 November, 2016
 ****************************************/

#include "Stack.h"


/***
 Constructor for initializing a stack.

 Complete, but not tested. I have malloced root before setting it to NULL other times. 
 I think this may create a litle bit of a memory leak though.
***/
Stack * newStack(void (* destroyFunction) (void * data), void (* printFunction) (void * dataToPrint)) {
    /* Allocate enough memory for a stack */
    Stack * stackPtr = malloc(sizeof(Stack));
    
    /* Initialize internal variables */
    stackPtr->stackSize = 0;
    stackPtr->root = NULL;
    stackPtr->push = &pushFunction;
    stackPtr->pop = &popFunction;
    
    /* Required function pointers */
    stackPtr->destroyNode = destroyFunction;
    stackPtr->toString = printFunction;
    
    return stackPtr;
}


/***
 Pushes a node into the front of the stack.
***/
void pushFunction(Stack * theStack, void * dataToAdd) {
	/* Allocate memory for a new node to add to the stack. */
	StackNode * newNode = malloc(sizeof(StackNode));
	newNode->dataInNode = dataToAdd;
	newNode->next = NULL;

	if (theStack->root == NULL) {
		/* Set root to the new node */
		theStack->root = newNode;
	} else {
		/* Shift the entire stack to a new node to the front */
		StackNode * temp = theStack->root;
		theStack->root = newNode;
		theStack->root->next = temp;
	}

	/* Iterate the size of the stack so stack size is always accurate */
	theStack->stackSize++;
}


/***
 Pops a node off of the top of the stack.

 Complete, but not tested
***/
void popFunction(Stack * theStack) {
	/*assert(theStack->root != NULL, "Error: Attempting to remove a node from an empty stack.");*/
	/* If the stack is not empty */
	if (theStack->root != NULL) {
		/* Redefine the root node */
		StackNode * temp = theStack->root;
		theStack->root = theStack->root->next;

		/* destroy the node pointer and then free the node itself*/
		theStack->destroyNode(temp->dataInNode);
		free(temp);

		/* Subtract one off of the node size*/
		theStack->stackSize--;
	} 
}

