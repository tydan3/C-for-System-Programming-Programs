// seec -cc std=gnu90 maximumEx1.c

#include <stdio.h>



int maximum(int, int, int);


int main() {
	

   int number1 = 25, number2 = 10, number3 = 99;

	

   printf("\nThe maximum value is %d\n", maximum(number1, number2, number3));

	
   return 0;
 
}



int maximum(int x, int y, int z) {
        
   int max = x;
        
        

   if (y > max)
           
      max = y;
   

   if (z > max)
           
      max = z;
           
        

   return max;

}