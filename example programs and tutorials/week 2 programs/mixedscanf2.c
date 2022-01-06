#include<stdio.h>

int main(void) {

	char  myChar;
	int myInt;

	printf("Type in a character: ");
	scanf("%c", &myChar);
	printf("The keystroke just accepted is %d\n", myChar);
	printf("\nType in an integer: ");
	scanf("%d", &myInt);
	printf("The keystroke just accepted is %d\n", myInt);
	return 0;
}
