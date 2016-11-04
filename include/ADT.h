/************************************************************************
 Abstracted data type header file, usable functions.
 
 Devin Rose
 August, 2015
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct studentInfo
{
    char * name;
    char * studentNumber;
}Sinfo;


/*Function prototypes are sorted by type, then sorted alphabetically*/

/*******************************
 ADT Functions
 *******************************/

/*****
 comparison function used for sorting elements into the tree, returns the following values for the comparison...
 
 compareOne & compareTwo
 compareOne > compareTwo returns > 0
 compareOne < compareTwo returns < 0
 compareOne = compareTwo returns = 0
 *****/

int compareName(void * ptrOne, void * ptrTwo);

/*****
 Allocates enough memory and fills the ADT variables with the desired input information. Because this function allocates enough memory to store all required information, pointers can be used without any more memory allocation.
 *****/

Sinfo * createADT(const char * inputString);

/*****
 This function frees all the memory the ADT requires. Use this function to free memory before freeing any pointer to the ADT that has not yet been freed.
 
 Use a void pointer to that points to the data you would like to free.
 *****/

void destroyADT(void * ptrToFree);

/*****
This function determines if the ADTs are equivalent from void pointers
 *****/

int equalsADT(void * ptrOne, void * ptrTwo);

/*****
 This function simply prints the data stored in the ADT. In order for other functions to print the data, a print function that uses a void pointer is required.
 *****/

void printADT(void * printPtr);





