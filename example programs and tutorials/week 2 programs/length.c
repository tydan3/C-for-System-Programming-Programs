#include <stdio.h>

int main(void)
{
   char ch;
   int len = 0;

   printf("Enter a message: ");

   ch = getchar();
   while (ch != '\n') {
	putchar(ch);
	len++;
	ch = getchar();	
   }

   printf("\nYour message was %d character(s) long.\n", len);

   return 0;
}
