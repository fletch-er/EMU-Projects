#include <stdio.h>
#include <math.h>

int main()
{
    /*
        Casey Fletcher 2/9/2021
        Calculate any given Fibonacci number
        using the golden ratio.

        Any Fibonacci number can be calculated using the following formula:
        (g^n - (1/g)^n) / sqrt(5)
        where g is the golden ratio
        and n is which Fibonacci number we want to return.
    */
    double ratio = (1 + sqrt(5)) / 2;
    double inverse_ratio = (-1/ratio);
    printf("Get what fib number: ");
    int in;
    scanf("%d", &in);
    double answer = ( pow(ratio, in) - pow(inverse_ratio, in) ) / sqrt(5);
    printf("%0.2lf", answer);
}
