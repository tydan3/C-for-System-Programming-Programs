#include <stdio.h>

#define SIZE 4

int* returnArray();

int main(void) {

	int  i;

	int* arr = returnArray();

	for (i=0; i<SIZE; i++)
		printf("%d ", arr[i]);

	return 0;
}

int* returnArray() {
	
	int i;

	int a[SIZE];
	printf("Enter %d ints: ", SIZE);
	for (i=0; i<SIZE; i++)
		scanf("%d", &a[i]);
	return a;
}

