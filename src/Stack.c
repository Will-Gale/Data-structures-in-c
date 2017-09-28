/****************************************
 Functions for creating and using a Stack.
 
 Stack.h
 
 devrows
 November, 2016
 ****************************************/

#include "Stack.h"



/***
 Constructor for initializing a stack.

 After passing function pointers, the stack is initialized by allocating memory for a stack and setting all unknown variables to NULL.
***/
Stack * newStack(void (* destroyFunction) (void * data), void (* printFunction) (void * dataToPrint), void (* writeFunction) (FILE * streamOut, void * dataToWrite), char * (* toStringFunction) (void * data)) {
    /* Allocate enough memory for a stack */
    Stack * stackPtr = malloc(sizeof(Stack));
    
    /* Initialize internal variables */
    stackPtr->stackSize = 0;
    stackPtr->root = NULL;
    stackPtr->push = &pushFunction;
    stackPtr->pop = &popFunction;
    stackPtr->destroy = &destroyStack;
    
    /* Required function pointers */
    stackPtr->destroyADT = destroyFunction;
    stackPtr->toString = toStringFunction;
    stackPtr->print = printFunction;
    stackPtr->write = writeFunction;

    return stackPtr;
}


/***
 Pushes a node into the front of the stack, memory is allocated for a single node.
***/
void pushFunction(Stack * theStack, void * dataToAdd) {
	/* Allocate memory for a new node to add to the stack. */
	StackNode * newNode;

	/* Do not allow the addition of NULL elements */
	if(dataToAdd == NULL) {
		return;
	}

	/* Allocate required memory after confirming the data to add is not NULL */
	newNode = malloc(sizeof(StackNode));
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
 Pops a node off of the top of the stack, no pointer is returned and memory from the node is freed.
***/
void popFunction(Stack * theStack) {
	/* If the stack is not empty or NULL */
	if (theStack != NULL && theStack->root != NULL) {
		/* Redefine the root node */
		StackNode * temp = theStack->root;
		theStack->root = theStack->root->next;

		/* destroy the node pointer and then free the node itself*/
		theStack->destroyADT(temp->dataInNode);
		temp->dataInNode = NULL;

		free(temp);
		temp = NULL;

		/* Subtract one off of the node size*/
		theStack->stackSize--;
	} 
}



/***
	Destroys the entire stack (frees the memory allocated for each individual node).

	Also frees the memory allocated by the stack itself, and sets the pointer to NULL.
***/

void destroyStack(Stack ** stackPtr) {
	Stack * theStack = *stackPtr;

	/* For a NULL/empty stack */
	if (theStack == NULL) {
		return;
	}

	while (theStack->root != NULL) {
		theStack->pop(theStack);
	}

	free(*stackPtr);
	*stackPtr = NULL;
}


