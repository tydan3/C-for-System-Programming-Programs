#include<stdio.h>

int main(void) {

	char  myChar;
	int myInt;

	printf("Type in an integer: ");
	scanf("%d", &myInt);
	printf("The keystroke just accepted is %d\n", myInt);
	printf("\nType in a character: ");
	scanf("%c", &myChar);
	printf("The keystroke just accepted is %d\n", myChar);
	return 0;
}
