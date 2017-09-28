/****************************************
 Header for creating and using a Stack.
 
 Stack.h
 
 devrows
 November, 2016
 ****************************************/


#include <stdio.h>
#include <stdlib.h>


/* Typedefs for the structures used by the Stack.c library */
typedef struct stackStruct Stack;
typedef struct stackElement StackNode;


/* Struct definitions */
struct stackStruct {
    void (* destroyADT) (void *);
    char * (* toString) (void *);
    void (* print) (void *);
    void (* write) (FILE *, void *);
    void (* push) (Stack *, void *);
    void (* pop) (Stack * );
    void (* destroy) (Stack **);
    
    int stackSize;
    StackNode * root;
};

struct stackElement {
    void * dataInNode;
    StackNode * next;
};


/******
 Constuctors
 ******/

/***
 Allocates memory for a new stack data structure and returns a pointer to the newly allocated memory.
 	Function pointers for a destroy function and print function must be supplied by the user. 
 newStack->destroyNode(void *userNodeToFree) - Accepts a void pointer supplied by the user for 
 	freeing a node allocated by the user.
 newStack->toString(void *toPrint) - Accepts a void pointer supplied by the user for printing the 
 	data within the node supplied by the user.
 newStack->push() - Function pointer for the push function located below.
 newStack->pop() - Function pointer for the pop function located below.

 The user must free this memory, a pointer to allocated memory for a stack is returned.

 Example Call: newStack(&destroyADT, &printADT, &writeToFileFunction, &adtToStringFunction);
 ***/

Stack * newStack(void (* destroyFunction) (void *), void (* printFunction) (void *), void (* writeFunction) (FILE *, void *), char * (* toStringFunction) (void *));


/***
 Push function will accept a void pointer to memory already allocated by the user and adds it to 
 	the front of the stack. Because of the limitations of c, theStack that is being added to must 
 	also be passed as an argument.

 There is a function pointer to this function for each stack created for easier use.

 Nothing is returned, the root will just point to a new node that was added.

 Example Call: theStack->push(theStack, vPtrToAdd);
 ***/

void pushFunction(Stack * theStack, void * dataToAdd);


/***
 Pop function will remove the first node from the list if it is not currently set to NULL. The node 
 	"popped" from the stack frees the data passed from a user with the supplied destroyNode 
 	function then frees is then frees the node itself.

 Currently frees the data added by the user in of the list, this function may be changed in the 
 	future to free the node itself but return a void pointer to the data pushed to the stack by a 
 	user.

 Nothing is returned but theStack->root will point to the next node in the list.

 Example Call: theStack->pop(theStack);
 ***/

void popFunction(Stack * theStack);


/***
 Frees all memory allocated within the stack. Sequentially pops off all nodes freeing their data 
 	individually until the stack is empty. Requires a pointer to the stack to free itself as well.

 Return: No return value.

 Example Call: theStack->destroy(&theStack);
***/

void destroyStack(Stack ** stackPtr); 
