/****************************************
 Testing function, iterates through a loop performing multiple tests.
 
 Devin Rose
 August, 2015
 ****************************************/

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {

    /* Run the individual testing functions from here, this will be extended to regression testing soon */
    system("./test/testExecutables/testIndividual docs/dataFile.txt 1");
    system("./test/testExecutables/testIndividual docs/dataFile.txt 2");

    return 0;
}


