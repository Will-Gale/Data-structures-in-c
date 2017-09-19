/************************************************************************
 Abstracted data type functions that are used as an example.

 Devin Rose
 August, 2015
 ************************************************************************/

#include "ADT.h"

/*******************************
 ADT Functions
 *******************************/


/*Nanme comparison using a void pointer*/
int compareName(void * ptrOne, void * ptrTwo) {
    int nameComparison;
    Sinfo * comparisonOne = (Sinfo *) ptrOne;
    Sinfo * comparisonTwo = (Sinfo *) ptrTwo;
    
    /*Comparing the students by last name*/
    nameComparison = strcmp(comparisonOne->name, comparisonTwo->name);
    
    return nameComparison;
}


/*Initializes an ADT that will be added to the tree */
Sinfo * createADT(const char * inputString) {
    char * cPtr;
    Sinfo * newStruct = malloc(sizeof(Sinfo));
    
    /*Allocates enough memory to store a string of the student name without the number and a string to store the student number*/
    newStruct->name = malloc(sizeof(char)*(strlen(inputString)-6));
    newStruct->studentNumber = malloc(sizeof(char)*7);
    
    /*Parse the string before the comma to copy it to the ADT name*/
    cPtr = malloc(sizeof(char)*strlen(inputString)+1);
    strcpy(cPtr, inputString);
    cPtr = strtok(cPtr, ",");
    strcpy(newStruct->name, cPtr);
    
    /*Copies the rest of the string (student number) to the ADT student number*/
    cPtr = strtok(NULL, ",");
    strcpy(newStruct->studentNumber, cPtr);
    
    /*Gets rid of the new line at the end of the string*/
    if (newStruct->studentNumber[strlen(newStruct->studentNumber)-1] == '\n') {
        newStruct->studentNumber[strlen(newStruct->studentNumber)-1] = '\0';
    }
    
    return newStruct;
}

/*Checks if ADTs are equivalent*/
int equalsADT(void * ptrOne, void * ptrTwo) {
    int studentNumberComparison;

    Sinfo * compareNumOne = (Sinfo *) ptrOne;
    Sinfo * compareNumTwo = (Sinfo *) ptrTwo;

    studentNumberComparison = strcmp(compareNumOne->studentNumber, compareNumTwo->studentNumber);

    if (compareName(ptrOne, ptrTwo) == 0 && studentNumberComparison == 0) {
        return 1;
    } else {
        return 0;
    }
}


/*frees the allocated memory in the ADT that the void pointer points to*/
void destroyADT(void * ptrToFree) {
    Sinfo * toDestroy = (Sinfo *) ptrToFree;
    
    /*frees allocated memory in the ADT, then set it to null*/
    free(toDestroy->name);
    free(toDestroy->studentNumber);
    free(ptrToFree);

    toDestroy->name = NULL;
    toDestroy->studentNumber = NULL;
    ptrToFree = NULL;
}


/* Print the information from void pointers */
void printADT(void * printPtr) {
    Sinfo * tempToPrint = (Sinfo *) printPtr;
    
    /*print out the data stored in the Rinfo ADT elementToPrint*/
    printf("%s,%s", tempToPrint->name, tempToPrint->studentNumber);
}


/* This function returns a string of the ADT content. This function returns a pointer to allocated memory and must be freed. */
char * toString(void * adtPtr) {
    char * toReturn;
    int stringSize;
    Sinfo * tempToString = (Sinfo *) adtPtr;

    
    if(tempToString != NULL) {
        /* Allocate enough memory for the entire ADT */
        stringSize = strlen(tempToString->name) + strlen(tempToString->studentNumber);
        toReturn = malloc(sizeof(char) * stringSize);

        /* Copy in the first string, concat a comma, then concat the last part*/
        strcpy(toReturn, tempToString->name);
        strcat(toReturn, ",");
        strcat(toReturn, tempToString->studentNumber);
        strcat(toReturn, "\0");
    } else {
        toReturn = NULL;
    }
    
    return toReturn;
}

