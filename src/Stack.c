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
***/
Stack * newStack(void (* destroyFunction) (void * data), void (* printFunction) (void * dataToPrint), void (* writeFunction) (FILE * streamOut, void * dataToWrite), char * (* toStringFunction) (void * data)) {
    /* Allocate enough memory for a stack */
    Stack * stackPtr = malloc(sizeof(Stack));
    
    /* Initialize internal variables */
    stackPtr->stackSize = 0;
    stackPtr->root = NULL;
    stackPtr->push = &pushFunction;
    stackPtr->pop = &popFunction;
    
    /* Required function pointers */
    stackPtr->destroyNode = destroyFunction;
    stackPtr->toString = toStringFunction;
    stackPtr->print = printFunction;
    stackPtr->write = writeFunction;

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
	/* If the stack is not empty or NULL */
	if (theStack != NULL && theStack->root != NULL) {
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



/***
	Destroys the entire stack (frees the memory allocated for each individual node).

	Also frees the memory allocated by the stack itself, and sets the pointer to NULL.
***/

void destroyStack(Stack * theStack) {
	/* For a NULL stack/empty */
	if (theStack == NULL || theStack->root == NULL) {
		return;
	}

	while (theStack->root->next != NULL) {
		StackNode * temp = theStack->root;
		theStack->root = theStack->root->next;

		theStack->destroyNode(temp->dataInNode);
		free(temp);
	}

	theStack->destroyNode(theStack->root->dataInNode);
	free(theStack->root);
	theStack->root = NULL;

	free(theStack);
	theStack = NULL;
}


