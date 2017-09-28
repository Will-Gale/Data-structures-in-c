/************************************************************************
 Abstracted data type functions that are used as an example.

 Devin Rose
 August, 2015
 ************************************************************************/

#include "ADT.h"

/*******************************
 ADT Functions
 *******************************/


/*Name comparison using a void pointer*/
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
    Sinfo * newStruct;

    /* Do not allocate memory for a NULL object*/
    if(inputString == NULL) {
        return NULL;
    }
    
    /* Allocates memory to store a string of the student name without the number and a string to store the student number */
    newStruct = malloc(sizeof(Sinfo));
    
    /*Parse the string before the comma to copy it to the ADT name*/
    cPtr = malloc(sizeof(char)*strlen(inputString)+1);
    strcpy(cPtr, inputString);
    cPtr = strtok(cPtr, ",");
    
    /* Fill studentName*/
    newStruct->name = malloc(sizeof(char)*(strlen(cPtr)+1));
    strcpy(newStruct->name, cPtr);
    strcat(newStruct->name, "\0");
    
    /* Copies the rest of the string (student number) to the ADT member studentNumber */
    cPtr = strtok(NULL, ",");

    /* Student number must be 6 characters long */
    newStruct->studentNumber = malloc(sizeof(char)*7);
    strcpy(newStruct->studentNumber, cPtr);
    
    /* Null terminator: Gets rid of the new line at the end of the string */
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

    if(toDestroy != NULL) {
        /*frees allocated memory in the ADT, then set it to null*/
        free(toDestroy->name);
        free(toDestroy->studentNumber);
        free(ptrToFree);

        toDestroy->name = NULL;
        toDestroy->studentNumber = NULL;
        ptrToFree = NULL;
    }
}


/* Print the information from void pointers, wrapper function for writeADT(stdout, printPtr) 
WARNING: This function writes the new line character at the end of the actual string. 

If only a string of the stored data is required, call the toString() function. */
void printADT(void * printPtr) {

    writeADT(stdout, printPtr);
}


/* Print the information from void pointers, 
WARNING: This function writes the new line character at the end of the actual string. 

If only a string of the stored data is required, call the toString() function. */
void writeADT(FILE * stream, void * printPtr) {
    Sinfo * tempToPrint = (Sinfo *) printPtr;
    
    /*print out the data stored in the Rinfo ADT elementToPrint*/
    fprintf(stream, "%s,%s\n", tempToPrint->name, tempToPrint->studentNumber);
}


/* This function returns a string of the ADT content. 
WARNING: This function returns allocated memory and must be freed. */
char * toString(void * adtPtr) {
    char * toReturn;
    int stringSize;
    Sinfo * tempToString = (Sinfo *) adtPtr;

    
    if(tempToString != NULL) {
        /* Allocate enough memory for the entire ADT */
        stringSize = strlen(tempToString->name) + strlen(tempToString->studentNumber);
        toReturn = malloc(sizeof(char) * stringSize);

        /* First string, a comma, second part, then concat null terminator */
        sprintf(toReturn, "%s,%s", tempToString->name, tempToString->studentNumber);
        strcat(toReturn, "\0");
    } else {
        toReturn = NULL;
    }
    
    return toReturn;
}

