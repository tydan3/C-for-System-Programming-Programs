#include <stdio.h>
#include <limits.h>

int main(void) {

   printf("The minimum value of SHORT INT = %hd\n", SHRT_MIN);
   printf("The maximum value of SHORT INT = %hd\n", SHRT_MAX);
   printf("Number of bytes used for SHORT INT = %d\n", sizeof(short int));
   puts("----------------------------------");

   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d\n", INT_MAX);
   printf("Number of bytes used for INT = %d\n", sizeof(int));
   puts("----------------------------------");

   printf("The minimum value of LONG INT = %ld\n", LONG_MIN);
   printf("The maximum value of LONG INT = %ld\n", LONG_MAX);
   printf("Number of bytes used for LONG INT = %d\n", sizeof(long int));
   puts("----------------------------------");
   
   /*
   printf("The minimum value of UNSIGNED SHORT INT = %d\n", 0);
   printf("The maximum value of UNSIGNED SHORT INT = %u\n", USHRT_MAX);
   printf("Number of bytes used for UNSIGNED SHORT INT = %d\n", sizeof(unsigned short int));
   puts("----------------------------------");

   printf("The minimum value of UNSIGNED INT = %d\n", 0);
   printf("The maximum value of UNSIGNED INT = %u\n", UINT_MAX);
   printf("Number of bytes used for UNSIGNED INT = %d\n", sizeof(unsigned int));
   puts("----------------------------------");

   printf("The minimum value of UNSIGNED LONG INT = %ld\n", 0L);
   printf("The maximum value of UNSIGNED LONG INT = %lu\n", ULONG_MAX);
   printf("Number of bytes used for UNSIGNED LONG INT = %d\n", sizeof(unsigned long int));
   puts("----------------------------------");
   */

   return 0;
}
