#include <string.h>
#include <stdio.h>

void myfunc(int arr[]);

int main() {
   int arr[8];
   int num = sizeof(arr);
   printf("Sizeof: %d\n", num);
   int arr2[8] = {1,2,3,4,5,6,7,8};
   memcpy(arr, arr2, sizeof(arr));
   myfunc(arr);
   return 0;
}

void myfunc(int arr[]) {
   int num = sizeof(arr);
}
