/************************************************************************
 Abstracted data type functions that are used as an example.

 Devin Rose
 August, 2015
 ************************************************************************/

#include "ADT.h"

/*******************************
 Functions
 *******************************/

/*comparison function used for sorting elements into the tree*/
int compareName(Sinfo * compareOne, Sinfo * compareTwo)
{
    int nameComparison;
    
    /*Sorting the students by last name*/
    nameComparison = strcmp(compareOne->name, compareTwo->name);
    
    return nameComparison;
}

/*Initializes an ADT that will be added to the tree */
Sinfo * createADT(const char * inputString)
{
    char * cPtr;
    Sinfo * newStruct = malloc(sizeof(Sinfo));
    
    /*allocates enough memory to store a string of the student name without the number and a string to store the student number*/
    newStruct->name = malloc(sizeof(char)*(strlen(inputString)-6));
    newStruct->studentNumber = malloc(sizeof(char)*7);
    
    /*Parse the string before the comma to copy it to the ADT name*/
    cPtr = malloc(sizeof(char)*strlen(inputString)+1);
    strcpy(cPtr, inputString);
    cPtr = strtok(cPtr, ",");
    strcpy(newStruct->name, cPtr);
    
    /*copies the rest of the string (student number) to the ADT student number*/
    cPtr = strtok(NULL, ",");
    strcpy(newStruct->studentNumber, cPtr);
    
    /*Getting rid of the new line ('\n') at the end of the string*/
    newStruct->studentNumber[strlen(newStruct->studentNumber)-1] = '\0';
    
    return newStruct;
}

/*frees allocated memory from the struct*/
void destroyADT(Sinfo * elementToFree)
{
    /*frees allocated memory in the ADT*/
    free(elementToFree->name);
    free(elementToFree->studentNumber);
}

/*prints "lastName,studentNumber"*/
void printADT(Sinfo * elementToPrint)
{
    /*print out the data stored in the Rinfo ADT elementToPrint*/
    printf("%s,%s", elementToPrint->name, elementToPrint->studentNumber);
}



/*******
 Dereferencing Functions, these are the functions passed to the data structures
 *******/

/*destroy from void pointer*/
void destroyVoid(void * ptrToFree)
{
    Sinfo * toDestroy = (Sinfo *) ptrToFree;
    
    destroyADT(toDestroy);
}

/*print the information from void pointers*/
void printVoid(void * sInfoPtr)
{
    Sinfo * tempToPrint = (Sinfo *) sInfoPtr;
    printADT(tempToPrint);
}


/*Nanme comparison using a void pointer*/
int voidCompareName(void * ptrOne, void * ptrTwo)
{
    int nameComparison;
    Sinfo * comparisonOne = (Sinfo *) ptrOne;
    Sinfo * comparisonTwo = (Sinfo *) ptrTwo;
    
    /*pass the ADTs to the compareName function*/
    nameComparison = compareName(comparisonOne, comparisonTwo);
    
    return nameComparison;
}


