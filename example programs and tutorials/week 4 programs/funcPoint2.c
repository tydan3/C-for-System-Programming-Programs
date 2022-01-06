#include <stdio.h>

int isOdd(int n);
int isEven(int n);
int isPositive(int n);
typedef int (*FName)(int);
FName mychoice(int choice);

int main(void) {

	int  choice, num;
	int (*f)(int);

	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("Enter the number to be checked: ");
	scanf("%d", &num);
	f = mychoice(choice);
	printf("%d\n", f(num));

	return 0;
}

FName mychoice(int choice) {
	int (*f[3])(int) = { isOdd, isEven, isPositive };
	return f[choice];
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

