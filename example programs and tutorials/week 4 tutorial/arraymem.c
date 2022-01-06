#include <stdio.h>
#include <string.h>

void read_first(double arr[], int arrSize);

int main() {
    int size;
    double doubles[3] = {1.25, 5.33, 9.99};
    printf("How big of an array?\n");
    scanf("%i", &size);

    double doubles2[size];

    read_first(doubles2, size);
    printf("array contents:\n");
    int i;
    for(i = 0; i < size; i++) {
        printf("%f\n", doubles2[i]);
    }

}

void read_first(double arr[], int arrSize) {
    int arrIndex = 0;
    double val;
    int i;
    for(i = 0; i < arrSize; i++) {
        printf("input double: \n");
        scanf("%lf", &val);
        arr[i] = val;
    }
}
