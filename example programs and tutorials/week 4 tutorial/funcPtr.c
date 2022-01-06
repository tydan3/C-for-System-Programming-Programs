// when compiling this code, use command gcc funcPtr2.c -lm

#include <math.h>
#include <stdio.h>

double compute_sum(/*5. Copy point 4 from function definition header */, double lo, double hi);

int main(void)
{
    // 1. Create a function pointer called fp, that takes a double as an argument and returns double
    double  sum;

    // 2. Assign function sin from math.h to fp
    sum = compute_sum(fp, 0.0, 1.0);
    printf("sum(sin): %f\n", sum);

    // 3. Assign function cos from math.h to fp
    sum = compute_sum(fp, 0.0, 1.0);
    printf("sum(cos): %f\n", sum);
    return 0;
}

// computes an approximation of the Riemann integral for either sin or cos, between lo and hi
// pre: low and hi assigned, funcp == sin or cos from math library
// post: returns integral between lo and hi for funcp
double compute_sum(/* in */ /* 4. Create parameter for function pointer called funcp */, /* in */ double lo, /* in */ double hi) {

    double  sum = 0.0;
    int i;

    // Add values returned by the pointed-to function '*funcp'
    for (i = 0;  i <= 100;  i++)
    {
        double  x, y;

        // Use the function pointer 'funcp' to invoke the function
        x = i / 100.0 * (hi - lo) + lo;
        y = // 6. call funcp and pass x to it
        sum += y;
    }
    return sum / 101.0;
}

