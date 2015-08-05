/****************************************
Main function, uses the data structures
 
 Devin Rose
 August, 2015
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT.h"

int main(int argc, const char * argv[])
{
    char studentNameBuffer[50];
    FILE * inputFile;
    Sinfo * test;
    
    if (argv[1] == NULL)
    {
        printf("Error: There is no data to enter, now exiting. \n");
        return 0;
    }
    
    inputFile = fopen(argv[1], "r");
    
    if (inputFile == NULL)
    {
        printf("Error: File could not be open, now exiting. /n");
        return 0;
    }
    
    
    printf("This function is currently being used to test the data structure functions that are being developed. \n");
    
    while (fgets(studentNameBuffer, 50, inputFile) != NULL)
    {
        test = createADT(studentNameBuffer);
        
        printf("%s,", test->name);
        printf("%s \n", test->studentNumber);
    }
    
    
    return 0;
}
