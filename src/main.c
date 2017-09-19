/****************************************
Main function, uses the data structures
 
 Devin Rose
 August, 2015
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Imported data types */
#include "ADT.h"
#include "avlTree.h"
#include "binTree.h"
#include "Stack.h"


/* 
 Main function for calling tests 
 */
int main(int argc, const char * argv[]) {
    FILE * inputFile;

    /* No command line argument */
    if (argv[1] == NULL) {
        printf("Error: There is no data to enter, now exiting. \n");
        return 0;
    }
    

    inputFile = fopen(argv[1], "r");
    
    if (inputFile == NULL) {
        /* No file was found */
        printf("Error: File could not be open, now exiting. /n");
    } else {
        /* Call testing function */

    }

    fclose(inputFile);
    
    return 0;
}

