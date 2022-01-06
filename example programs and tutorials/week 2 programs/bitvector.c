#include <stdio.h>

#define T142 128
#define T143 64
#define T305 32
#define T321 16
#define T325 8
#define T333 4
#define T342 2
#define T371 1
#define BITS 8


void printClasses (unsigned char bitVector);

int main(void) {

   unsigned char myClasses = 0;

   printClasses (myClasses);

   // add 142 and 143 to myClasses
   printClasses (myClasses);
   // add 325 to myClasses
   printClasses (myClasses);
   // remove 142 from myClasses
   printClasses (myClasses);

   return 0;
}

void printClasses (unsigned char bitVector) {

   const unsigned char mask = 128;
   int i;

   printf("classes: ");   
		
   for (i = 1; i <= sizeof(char) * BITS; i++) {

	if (bitVector & mask)
		putchar('1');
	else
		putchar('0');
        bitVector <<= 1;
		
   }
   printf("\n");
}

