/************************************************************************
 Abstracted data type header file, usable functions
 
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
 Functions
 *******************************/














/*****
 comparison function used for sorting elements into the tree, returns the following values for the comparison...
 
 compareOne & compareTwo
 compareOne > compareTwo returns > 0
 compareOne < compareTwo returns < 0
 compareOne = compareTwo returns = 0
 *****/

int compareName(Sinfo * compareOne, Sinfo * compareTwo);








/*Allocates enough memory and fills the ADT variables*/
Sinfo * createADT(const char * inputStudent);









void destroyADT(Sinfo * elementToFree);









void printStruct(Sinfo * elementToPrint);










/*******************************
 Dereferencing Functions
 
 These will be the functions that are passed as arguments to the other files
 *******************************/

void destroyVoid(void * ptrToFree);










void printVoid(void * rInfoPtr);











int voidCompareName(void * ptrOne, void * ptrTwo);


