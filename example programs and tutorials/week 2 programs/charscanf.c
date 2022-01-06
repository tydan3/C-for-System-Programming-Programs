#include<stdio.h>

int main(void) {

	char  myChar1, myChar2;

	printf("Type in a character: ");
	scanf("%c", &myChar1);
	printf("The keystroke just accepted is %d\n", myChar1);
	printf("\nType in another character: ");
	scanf("%c", &myChar2);
	printf("The keystroke just accepted is %d\n", myChar2);
	return 0;
}
