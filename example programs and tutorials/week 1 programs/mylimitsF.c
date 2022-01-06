#include <stdio.h>
#include <float.h>

int main(void) {

   printf("Number of bytes used for FLOAT = %d\n", sizeof(float));
   printf("Minimum floating point number = %g\n", FLT_MIN);
   printf("Maximum floating point number = %e = %f\n", FLT_MAX);
   puts("----------------------------------");

   
   printf("Number of bytes used for DOUBLE = %d\n", sizeof(double));
   printf("Minimum double point number = %g\n", DBL_MIN);
   printf("Maximum double point number = %lg\n", DBL_MAX);
   puts("----------------------------------");

   
   printf("Number of bytes used for LONG DOUBLE = %d\n", sizeof(long double));
   printf("Minimum long double point number = %Lg\n", LDBL_MIN);
   printf("Maximum long double point number = %Lg\n", LDBL_MAX);
   puts("----------------------------------");
   
   return 0;
}
