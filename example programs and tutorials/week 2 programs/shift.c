#include <stdio.h>

#define BITS 8

int main(void) {

   int x = 2, i;
	
   for (i = 1; i <= sizeof(int) * BITS; i++) {
	
       printf("x = %d\n", x);

       x = x << 1;
		
   }
   printf("\n");
   
   return 0;
}
