#include <stdio.h>
#include <limits.h>

int main(void) {

   unsigned int num = -1;
   unsigned int num2, num3;
   
   printf("%u %d\n", num, num);

   num2 = num - 1;
   num3 = num + 1;
   printf("%u %d\n", num2, num2);
   printf("%u %d\n", num3, num3);
  
   return 0;
}
