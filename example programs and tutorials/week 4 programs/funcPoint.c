#include <stdio.h>

int isOdd(int n);
int isEven(int n);
int isPositive(int n);

int main(void) {

	int  choice, num;
	int (*f[3])(int) = { isOdd, isEven, isPositive };

	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("Enter the number to be checked: ");
	scanf("%d", &num);

	printf("%d\n", (*f[choice])(num));

	return 0;
}

int isEven(int n) {
	return !isOdd(n);
}

int isOdd(int n) {
	return n % 2;
}

int isPositive(int n) {
	return n > 0;
}

