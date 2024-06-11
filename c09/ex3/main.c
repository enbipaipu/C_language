/* ex2 */

#include <stdio.h>

extern double integral(double x1, double x2, double (*f)(double));

static double g(double x)
{
    return 1 / (x * x + 1);
}

int main()
{
    double s = integral(0.0, 1.0, g);
    printf("pi is approximately %f\n", s * 4);

    return 0;
}