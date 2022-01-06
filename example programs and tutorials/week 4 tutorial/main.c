#include "square.c"

#define MY_X 10
#define MY_SQUARE(x) ((x) * (x))
#define PRINT  2
#define four_bytes int

int main() {

   // this program shows the usage of pre-processor directives 
  
   four_bytes	x, s1, s2;

   #if PRINT == 1
       printf("Enter any integer: ");
       scanf("%d",&x);
       s1 = Square(x);
       printf("Function: The square of %d is %d\n", x, s1);
   #endif
   #if PRINT == 2
      s1 = MY_X;
      s2 = MY_SQUARE(s1);
      printf("Macro: The square of %d is %d\n", MY_X, s2);
   #endif
   
}
