/****************************************
 Testing function, iterates through a loop performing multiple tests.
 
 DevRows
 September, 2017
 ****************************************/

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/***
    Main testing function, this main calls another program for individual tests in the case of a failed test.

    Functionality can be added later to test various files instead of hardcoding the only current file.
***/
int main(int argc, const char * argv[]) {
    char * testString = "./test/testExecutables/testIndividual docs/dataFile.txt";
    char * runCommand = malloc(sizeof(char) * (strlen(testString) + 4));
    int testNum;
    
    /* Test types */
    char * test[2];
    test[0] = "Binary Tree Functions";
    test[1] = "Stack Functions";

    for (testNum = 0; testNum < 2; testNum++) {
        /* Generate the command as a string, then add the null terminator */
        sprintf(runCommand, "%s %d", testString, testNum);
        strcat(runCommand, "\0");

        /* Print a statement notifying the user which test is currently running */
        fprintf(stdout, "***\n\tTesting Suite %d: Now using the supplied ADT to to test: %s\n***\n", testNum, test[testNum]);

        /* Runs an individual test functions from another file with this command */
        system(runCommand);
    }

    /* Frees the allocated memory from the string used to run the individual test programs */
    free(runCommand);

    return 0;
}


