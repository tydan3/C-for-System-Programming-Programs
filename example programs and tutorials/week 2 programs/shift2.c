#include <stdio.h>

#define BITS 8

int main(void) {

   int x = 2, i;
   int mask = 1 << sizeof(int) * BITS - 1;
   
   //printf("%d\n", mask);

   printf("x = %d\n", x);
	
   for (i = 1; i <= sizeof(int) * BITS; i++) {
	
		if (x & mask)
			putchar('1');
		else
			putchar('0');

		x <<= 1;
		if (! (i % 8)) {
			putchar(' ');
		} 
   }
	printf("\n");
   
   return 0;
}
