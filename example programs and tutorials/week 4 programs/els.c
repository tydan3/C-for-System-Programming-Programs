#include <stdio.h>

void myprint(const int array[], int);


int main(void) {

	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	// call to compareEls passing first two els

	printf("Print array elements after compareEls\n");
	myprint(arr, 7);

	// call to swapEls passing first two els

	printf("Print array elements after swapEls\n");
	myprint(arr, 7);

	return 0;
}

void myprint(const int array[], int size) {
	int i;
	for (i=0; i < size; i++) 
		printf("%d ", array[i]);
	printf("\n");
}

// function header for compareEls {
	if (a < b)
		printf("first el smaller\n");
	else
		printf("either equal or second el larger\n");

}




	
