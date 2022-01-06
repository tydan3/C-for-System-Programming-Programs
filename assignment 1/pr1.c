#include <stdio.h>

int print_bits(int decValue, int bits);
void display_1();
void display_2();
void display_3();
void display_4();

int main() {
    short displayInput;
    char repeat;
    
    do {
        // ask for display input
        printf("\nWhat type of display do you want?\n");
        printf("Enter 1 for IP/RGB, 2 for character concatenation, 3 for character parity, 4 for filtering: ");
        scanf("%hi", &displayInput);

        // invalid display input
        while (displayInput < 1 || displayInput > 4) {
            printf("Invalid input, try again\n\n");
            printf("------------------------------------------------------------------------\n\n");
            printf("What type of display do you want?\n");
            printf("Enter 1 for IP/RGB, 2 for character concatenation, 3 for character parity, 4 for filtering: ");
            scanf("%hi", &displayInput);
        }

        printf("\n");

        switch (displayInput) {
        case 1: // IP/RGB
            display_1();
            break;
        case 2: // character concatenation
            display_2();
            break;
        case 3: // character parity
            display_3();
            break;
        case 4: // filtering
            display_4();
            break;
        }

        printf("\n\nEnter r to repeat, and anything to quit: ");
        scanf(" %c", &repeat);
        if (repeat == 'r')
            printf("\n------------------------------------------------------------------------\n");

    } while (repeat == 'r');
}

// Prints bit representation of a integer given a bit size.
// Returns number of 1's in bit representation.
int print_bits(int decValue, int bits) {
    int i;
    int mask = 1 << bits - 1;
    int numOfOnes = 0;

    for (i = 1; i <= bits; i++) {
        if (decValue & mask) {
            putchar('1');
            numOfOnes++;
        }   else
            putchar('0');

        decValue <<= 1;
        if (! (i % 8)) {
            putchar(' ');
        } 
    }
    return numOfOnes;
}


void display_1() {
    int value;
    printf("Enter a positive integer for the IP/RGB value: ");
    scanf("%i", &value);
    printf("You entered: %i", value);
    printf(", Bit representation: ");
    print_bits(value, 32); 
    printf("\nThe dot-decimal represented by this number is: ");

    int octet = 0;
    int mask = 1 << 32 - 1;
    int i;
    for (i = 1; i <= 32; i++) {
        if (value & mask) {
            if (i % 8 == 0) {
                octet += 1; // 2^0
            } else {
                octet += 256 >> (i % 8); // 2^1 to 2^7
            }
        }

        value <<= 1;
        if (i == 32) {
            printf("%i", octet);
        } else if (!(i % 8)) {
            printf("%i", octet);
            putchar('.');
            octet = 0;
        } 
    }

}

void display_2() {
    char char1, char2, char3, char4;
    int dec1, dec2, dec3, dec4;
    printf("Enter 4 characters: ");
    scanf(" %c%c%c%c", &char1, &char2, &char3, &char4);
    dec1 = (int) char1;
    dec2 = (int) char2;
    dec3 = (int) char3;
    dec4 = (int) char4;
    printf("%i, Bit representation: ", dec1);
    print_bits(dec1, 8);
    printf("%i, Bit representation: ", dec2);
    print_bits(dec2, 8);
    printf("%i, Bit representation: ", dec3);
    print_bits(dec3, 8);
    printf("%i, Bit representation: ", dec4);
    print_bits(dec4, 8);

    int concat = dec1;
    concat <<= 8;
    concat |= dec2;
    concat <<= 8;
    concat |= dec3;
    concat <<= 8;
    concat |= dec4;
    printf("32-bit concatenation is: %i, Bit representation: ", concat);
    print_bits(concat, 32);
}

void display_3() {
    char char1;
    int dec1;
    printf("Enter a character for parity calculation: ");
    scanf(" %c", &char1);
    dec1 = (int) char1;
    printf("Character: %i, Bit representation: ", dec1);
    int numOfBits = print_bits(dec1, 8);
    printf("\nNumber of ones: %i\n", numOfBits);

    if (numOfBits % 2 == 0) {
        dec1 |= 128;
    }
    printf("Odd 1 parity for the character is: %i, Bit representation: ", dec1);
    print_bits(dec1, 8);
}


void display_4() {
    int input;
    printf("Enter an integer to filter: ");
    scanf("%i", &input);
    printf("You entered: %i, Bit representation: ", input);
    print_bits(input, 32);
    printf("\n");

    int mute;
    while (1) {
        // Assumes bits to be muted are 1's (cannot mute 0's)
        printf("Enter which bit you want to mute (enter 0 to quit): ");
        scanf("%i", &mute);

        if (mute == 0) {
            return;
        } else if (mute < 0 || mute > 32) {
            printf("Invalid bit, try again\n");
        } else {
            int mask = 1 << mute - 1;
            input -= mask;
            printf("The new value is: %i, Bit representation: ", input);
            print_bits(input, 32);
            printf("\n");
        }
    }
}