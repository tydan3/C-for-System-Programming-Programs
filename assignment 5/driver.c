/** 
Daniel Ty
TCSS 333
Programming assignment 5
Tested in cssgate server
*/  

#include <stdio.h>
#include "operations.h"

int main(void) {
    int opNum;
    FILE* filePtr = fopen("animals.dat", "rb+");
    
    // save temporary copy of records
    FILE* tempPtr = tmpfile();
    copyRecords(tempPtr, filePtr);

    do {
        puts("-----");

        // get user input for operation selection
        printf("Select an operation to perform (0-5): ");
        scanf("%i", &opNum);

        switch (opNum) {
            case 0:
                puts("outputting to csv...");

                // write changes to csv
                FILE* csvPtr = fopen("animals.csv", "w");
                outputToCsv(filePtr, csvPtr);
                fclose(csvPtr);

                // revert animals.dat back to saved records
                copyRecords(filePtr, tempPtr);
                fclose(tempPtr);
                fclose(filePtr);

                puts("exiting program");
                break;

            case 1:
                opOne(filePtr);
                break;

            case 2:
                opTwo(filePtr);
                break;

            case 3:
                opThree(filePtr);
                break;

            case 4:
                opFour(filePtr);
                break;

            case 5:
                opFive(filePtr);
                break;

            default: // inputs outside of 0-5 are invalid
                puts("invalid operation input");
                break;
        }

        rewind(filePtr);
    } while (opNum != 0);

    puts("-----");
    return 0;
}