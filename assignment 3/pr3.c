#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <math.h> 


/** 
Daniel Ty
TCSS 333
Programming assignment 3
Tested in cssgate server
*/  

// function declarations
int isOperand(char* theString);
int isOperator(char* theString);
char* add(char* theAugend, char* theAddend);
char* multiply(char* theMultiplicand, char* theMultiplier);
int* createCounters(char* theString);
int getCountersValue(int* theCounters);
char* createStringFromCounters(int* theCounters);
void modifyCounters(int* theCounters, int theTotalValue);
void toLowercase(char* theString);
void printCounters(int* theArray);

// global constants
#define ALPHABET_SIZE 26
#define ASCII_OFFSET 97


int main(int argc, char* argv[]) {

    puts("---");

    // echo print command-line arguments
    size_t i;
    for(i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    puts("");

    if (argc != 4) { // check for valid # of arguments
        puts("invalid number of arguments");

    } else {
        // obtain operands and operator
        char* leftOperand = argv[1];
        char* operator = argv[2];
        char* rightOperand = argv[3];

        // check if operands and operator are valid
        if (!isOperand(leftOperand) || !isOperand(rightOperand)) {
            puts("invalid operand");
        }
        if (!isOperator(operator)) {
            puts("invalid operator");
        }

        if (isOperand(leftOperand) && isOperand(rightOperand)
            && isOperator(operator)) {
            
            // perform corresponding operations according to operator.
            if (*operator == '+') {
                char* sum = add(leftOperand, rightOperand);
                printf("%s + %s => %s\n", leftOperand, rightOperand, sum);

                // free memory allocated in function
                free(sum);

            } else if (*operator == 'x') {
                char* product = multiply(leftOperand, rightOperand);
                printf("%s x %s => %s\n", leftOperand, rightOperand, product);

                // free memory allocated in function
                free(product);            
            }
        }
    }

    printf("---\n");

    return 0;
}

/* Checks if string is a valid operand. 
 * pre: theString is not null
 * post: Returns true if theString contains only letters, else false. 
 */
int isOperand(char* theString) {
    // return true by default
    int returnMe = 1;
    int size = strlen(theString);
    size_t i;

    // iterate over each char of the string
    for (i = 0; i < size; i++) {
        // change return to 0 if any char is not a letter
        if (!isalpha(theString[i])) {
            returnMe = 0;
        }
    }

    return returnMe;
}

/* Checks if string is a valid operator. 
 * pre: theString is not null
 * post: Returns true if theString contains only a '+' or an 'x',
 *       else false. 
 */
int isOperator(char* theString) {
    // return false by default
    int returnMe = 0;
    int size = strlen(theString);

    // change return to true if theString is '+' or 'x'
    if (size == 1 && *theString == '+' || *theString == 'x') {
        returnMe = 1;
    }

    return returnMe;
}

/* Performs addition on two strings according to Napier's notation
 * pre: theAugend and theAddend are valid operands, determined by isOperand()
 * post: returns the sum of the operands in Napier's notation as a String
 */
char* add(char* theAugend, char* theAddend) {
    // merge operands into a single string
    int totalLetters = strlen(theAugend) + strlen(theAddend);
    char* merged = (char*) calloc(totalLetters + 1, sizeof(char));
    strcpy(merged, theAugend);
    strcat(merged, theAddend);

    // lowercase the merged string
    toLowercase(merged);

    // use merged string to create letter counters
    int* letterCounters = createCounters(merged);

    // get total decimal value of letter counters
    int totalDecimal = getCountersValue(letterCounters);

    // modify one of the operand counters to reflect the sum decimal
    modifyCounters(letterCounters, totalDecimal);

    // create the corresponding sum string from the modified counter
    char* sum = createStringFromCounters(letterCounters);

    // free memory
    free(letterCounters);
    free(merged);

    return sum;
}

/* Performs multiplication two strings according to Napier's notation
 * pre: theMultiplicand and theMultiplier are valid operands, determined by isOperand()
 * post: returns the product of the operands in Napier's notation as a String
 */
char* multiply(char* theMultiplicand, char* theMultiplier) {
    // allocate memory for multiplier and multiplicand strings
    char* multiplicand = (char*) calloc(strlen(theMultiplicand) + 1, sizeof(char));
    char* multiplier = (char*) calloc(strlen(theMultiplier) + 1, sizeof(char));
    
    // copy strings from parameters and lowercase them
    strcpy(multiplicand, theMultiplicand);
    strcpy(multiplier, theMultiplier);
    toLowercase(multiplicand);
    toLowercase(multiplier);

    // create letter counters arrays from operands
    int* multiplicandCounters = createCounters(multiplicand);
    int* multiplierCounters = createCounters(multiplier);

    // free operand strings
    free(multiplicand);
    free(multiplier);

    // product decimal value = multiplicand decimal value x multiplier decimal value
    int productDecimal = getCountersValue(multiplicandCounters) *
        getCountersValue(multiplierCounters);

    // modify one of the operand counters to reflect the product decimal
    modifyCounters(multiplicandCounters, productDecimal);

    // create the corresponding product string from the modified counter
    char* product = createStringFromCounters(multiplicandCounters);

    // free letter counter arrays
    free(multiplicandCounters);
    free(multiplierCounters);

    return product;
}

/* Creates a letter counters array from passed in String.
 * pre: theString is a valid operand, determined by isOperand()
 * post: returns an array of letter counters with letters counted from
 *       theString
 */
int* createCounters(char* theString) {
    int* letterCounters = (int*) calloc(ALPHABET_SIZE, sizeof(int));
    size_t i;
    // iterate over string and add its letters to corresponding their counter
    for (i = 0; i < strlen(theString); i++) {
        int asciiDec = (int) theString[i];
        letterCounters[asciiDec - ASCII_OFFSET]++;
    }
    return letterCounters;
}

/* Returns the total value of the counters as a decimal
 * pre: theCounters is of length 26 and does not contain null contents
 * post: Returns total value as decimal
 */
int getCountersValue(int* theCounters) {
    int totalValue = 0;
    // iterate over letter counters
    size_t i;
    size_t j;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        // iterate over number of letters in a counter
        for (j = 0; j < theCounters[i]; j++) {
            // letter's value equals 2 to the power of its counter index
            int value = pow(2, i);
            // for each letter, add its value to totalValue
            totalValue += value;
        }
    }
    return totalValue;
}

/* Modifies a counters array to match a decimal value
 * pre: theCounters is of length 26 and does not contain null contents,
 *      theTotal is not null
 * post: theCounters is modified to have its total value in decimal equal
 *       theTotal
 */
void modifyCounters(int* theCounters, int theTotal) {
    int totalValue = theTotal;

    // clear letter counters
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        theCounters[i] = 0;
    }

    // iterate from z to a and subtract their values from totalValue until 
    // it equals 0.
    for (i = ALPHABET_SIZE - 1; i >= 0; i--) {
        int value = pow(2, i);

        // if difference is nonnegative, subtract letter's value from totalValue
        while (totalValue - value >= 0) {
            totalValue -= value;
            // increment corresponding letter counter
            theCounters[i]++;
        }
    }
}

/* Creates a String from the passed in letter counters array.
 * pre: theCounters is of length 26 and does not contain null contents
 * post: returns countersString, a String of all letters in the counters
 */
char* createStringFromCounters(int* theCounters) {
    // find total # of letters in counters
    int totalLetters = 0;
    size_t i;
    size_t j;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        for (j = 0; j < theCounters[i]; j++) {
            totalLetters++;
        }
    }

    // allocate memory for counters string
    char* countersString = (char*) calloc(totalLetters + 1, sizeof(char));

    // append each letter from letter counters onto countersString
    for (i = 0; i < ALPHABET_SIZE; i++) {
        for (j = 0; j < theCounters[i]; j++) {
            int asciiDec = i + ASCII_OFFSET;
            char ch = (char) asciiDec;
            strncat(countersString, &ch, 1);
        }
    }
    return countersString;
}

/* Lowercases the passed in String
 * pre: theString is not null and contains only letters
 * post: theString has its characters lowercased
 */
void toLowercase(char* theString) {
    // iterate over the string
    size_t i;
    for (i = 0; i < strlen(theString); i++) {
        // lowercase each char
        theString[i] = tolower(theString[i]);
    }
}

/* Util function used to print array of counters for testing
 * pre: theCounters is of length 26 and does not contain null contents
 * post: none
 */
void printCounters(int* theCounters) {
    printf("[");
    size_t i;
    // iterate over the array and print its contents
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (i < ALPHABET_SIZE - 1) {
            printf("%d, ", theCounters[i]);
        } else {
            printf("%d]\n", theCounters[i]);
        }
    }
}