#include <stdio.h>
#include "operations.h"

/* Perform processing similar to the strings command in Unix
 * pre: theFilePtr points to a valid file
 * post: none
 */

void opOne(/*inout*/ FILE* theFilePtr) {
    char letter;
    int lineLength = 0;

    while(!feof(theFilePtr)) {
        int result = fread(&letter, sizeof(char), 1, theFilePtr);

        if (result != 0) {

            // print ascii if between 32 and 126
            if ((int) letter >= 32 && (int) letter <= 126) {
                printf("%c", letter);

            // else .
            } else {
                printf(".");
            }

            // increment line length for character
            lineLength++;
            
            // if at 80, new line and reset
            if (lineLength == 80) {
                puts("");
                lineLength = 0;
            }
        }

    }
    puts("");

}

/* Perform processing similar to the way numbers are displayed in the ghex editor
 * pre: theFilePtr points to a valid file
 * post: none
 */
void opTwo(/*inout*/ FILE* theFilePtr) {
    int num;
    int numLength = 0; // used to count digits in number
    int lineLength = 0; // used to count length of printed line

    while(!feof(theFilePtr)) {
        int result = fread(&num, sizeof(int), 1, theFilePtr);

        if (result != 0) {
            // use temp to find # of digits in number
            numLength = 0;
            int temp = num;

            // increment number length for each digit
            do {
                ++numLength;
                temp /= 10;
            } while (temp);

            // number length and proceeding space added to line length
            lineLength += numLength + 1;

            // print number with space when below 80
            if (lineLength <= 80) {
                printf("%i ", num);

            // print number with next line (no space) when at 81
            } else if (lineLength == 81) {
                printf("%i\n", num);
                lineLength = 0;

            // print number on next line with space when above 81
            } else {
                puts("");
                printf("%i ", num);
                lineLength = numLength + 1;
            }
        }
    }
    puts("");

}

/* Select animal record and display to the screen
 * pre: theFilePtr points to a valid file
 * post: none
 */
void opThree(/*inout*/ FILE* theFilePtr) {
    // create animal with default values
    struct animal myAnimal = {0, "", "", '0', 0};

    // search for record by ID and print it if found
    if (seekID(theFilePtr)) {
        fread(&myAnimal, sizeof(struct animal), 1, theFilePtr);
        printf("%hi,%s,%s,%c,%hi\n", myAnimal.id, myAnimal.name, myAnimal.species,
            myAnimal.size, myAnimal.age);
    }
}

/* Select animal record and modify an attribute
 * pre: theFilePtr points to a valid file
 * post: none
 */
void opFour(/*inout*/ FILE* theFilePtr) {
    // search for record to modify
    if (seekID(theFilePtr)) {
        // get user input for attribute selection
        char attribute;
        puts("Select an attribute to modify.");
        printf("Enter n for name, p for species, s for size, or a for age: ");
        scanf(" %c", &attribute);

        switch (attribute) {
            case 'n':
                {
                // get user input for new name
                char newName[20];
                printf("Enter new name: ");
                scanf(" %[^\n]s", newName);

                // move pointer past id bytes
                fseek(theFilePtr, sizeof(short), SEEK_CUR);

                // write new name to file
                fwrite(newName, sizeof(char), 20, theFilePtr);
                }
                break;

            case 'p':
                {
                // get user input for new species
                char newSpecies[35];
                printf("Enter new species: ");
                scanf(" %[^\n]s", newSpecies);

                // move pointer past id and name bytes
                fseek(theFilePtr, sizeof(short) + sizeof(char) * 20, SEEK_CUR);

                // write new species to file
                fwrite(newSpecies, sizeof(char), 35, theFilePtr);
                }
                break;

            case 's':
                {
                // get user input for new size
                char newSize;
                printf("Enter new size: ");
                scanf(" %c", &newSize);

                // move pointer past id, name, and species bytes
                fseek(theFilePtr, sizeof(short) + sizeof(char) * 20 + 
                    sizeof(char) * 35, SEEK_CUR);

                // write new size to file
                fwrite(&newSize, sizeof(char), 1, theFilePtr);
                }
                break;

            case 'a':
                {
                // get user input for new age
                short newAge;
                printf("Enter new age: ");
                scanf("%hi", &newAge);

                // move pointer past id, name, species, and size bytes
                fseek(theFilePtr, sizeof(short) + sizeof(char) * 20 + 
                    sizeof(char) * 35 + sizeof(char), SEEK_CUR);

                // write new age to file
                fwrite(&newAge, sizeof(short), 1, theFilePtr);
                }
                break;

            default:
                puts("invalid letter input");
                break;
        }
    }

}

/* Select animal record and replace with last record
 * pre: theFilePtr points to a valid file
 * post: none
 */
void opFive(/*inout*/ FILE* theFilePtr) {
    // create animal with default values
    struct animal myAnimal = {0, "", "", '0', 0};

    // read last record into myAnimal struct
    fseek(theFilePtr, sizeof(struct animal) * -1, SEEK_END);
    int lastByte = ftell(theFilePtr);
    fread(&myAnimal, sizeof(struct animal), 1, theFilePtr);

    // search for record by ID
    if (seekID(theFilePtr)) {
        // write last record attributes to current record on file (except id)
        fseek(theFilePtr, sizeof(short), SEEK_CUR);
        fwrite(myAnimal.name, sizeof(char), 20, theFilePtr);
        fwrite(myAnimal.species, sizeof(char), 35, theFilePtr);
        fwrite(&myAnimal.size, sizeof(char), 1, theFilePtr);
        fwrite(&myAnimal.age, sizeof(short), 1, theFilePtr);

        // Remove last record from file
        ftruncate(fileno(theFilePtr), lastByte);
    }
}

/* Move pointer to record id selected by user input
 * pre: theFilePtr points to a valid file
 * post: return 1 if pointer is moved, else 0
 */
int seekID(/*inout*/ FILE* theFilePtr) {
    int isMoved;

    // find total records in file
    fseek(theFilePtr, 0, SEEK_END);
    int totalBytes = ftell(theFilePtr);
    int totalRecords = totalBytes / sizeof(struct animal);

    // get user input for id number
    int idNum = 0;
    printf("Enter ID to select record (1-%i): ", totalRecords);
    scanf("%hi", &idNum);

    if (idNum < 1 || idNum > totalRecords) {
        puts("invalid ID input");
        isMoved = 0;
    } else {
        // move file position to selected record
        fseek(theFilePtr, sizeof(struct animal) * (idNum - 1), SEEK_SET);
        isMoved = 1;
    }

    return isMoved;
}

/* Perform processing similar to the way numbers are displayed in the ghex editor
 * pre: theFilePtr and theCsvPtr points to valid files
 * post: theCsvPtr's file is overwritten to match theFilePtr's file 
 */
void outputToCsv(/*in*/ FILE* theFilePtr, /*out*/ FILE* theCsvPtr) {
    // create animal with default values
    struct animal myAnimal = {0, "", "", '0', 0};

    // find total records in file
    fseek(theFilePtr, 0, SEEK_END);
    int totalBytes = ftell(theFilePtr);
    int totalRecords = totalBytes / sizeof(struct animal);

    // iterate through records
    int i;
    for (i = 0; i < totalRecords; i++) {
        fseek(theFilePtr, sizeof(struct animal) * i, SEEK_SET);
        fread(&myAnimal, sizeof(struct animal), 1, theFilePtr);

        // print to csv if name is not unknown
        if (strcmp(myAnimal.name, "unknown")) {
            fprintf(theCsvPtr, "%hi,%s,%s,%c,%hi\n", myAnimal.id,
                myAnimal.name, myAnimal.species, myAnimal.size,
                myAnimal.age);
        }
    }
}

/* Perform processing similar to the way numbers are displayed in the ghex editor
 * pre: theFilePtr and theCsvPtr points to valid files
 * post: theDest's file is overwritten to match theSource's file
 */
void copyRecords(/*out*/ FILE* theDest, /*in*/ FILE* theSource) {
    // create animal with default values
    struct animal myAnimal = {0, "", "", '0', 0};

    // find total records in file
    fseek(theSource, 0, SEEK_END);
    int totalBytes = ftell(theSource);
    int totalRecords = totalBytes / sizeof(struct animal);

    // iterate through records
    int i;
    for (i = 0; i < totalRecords; i++) {
        fseek(theSource, sizeof(struct animal) * i, SEEK_SET);
        fread(&myAnimal, sizeof(struct animal), 1, theSource);

        fseek(theDest, sizeof(struct animal) * i, SEEK_SET);
        fwrite(&myAnimal, sizeof(struct animal), 1, theDest);
    }

    rewind(theDest);
    rewind(theSource);
}