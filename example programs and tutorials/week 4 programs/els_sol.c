#include <stdio.h>

void myprint(const int array[], int);
void compareEls(int, int);
void swapEls(int *a, int *b);

int main(void) {

	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	compareEls(arr[0], arr[1]);

	printf("Print array elements after compareEls\n");
	myprint(arr, 7);

	swapEls(&arr[0], &arr[1]);

	printf("Print array elements after swapEls\n");
	myprint(arr, 7);

	return 0;
}


void compareEls(int a /*in*/, int b /*in*/) {
	if (a < b)
		printf("first el smaller\n");
	else
		printf("either equal or second el larger\n");

}

void swapEls(int *a /*inout*/, int* b /*inout*/) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void myprint(const int array[] /*in*/, int size /*in*/) {
	int i;
	for (i=0; i < size; i++) 
		printf("%d ", array[i]);
	printf("\n");
}


	
