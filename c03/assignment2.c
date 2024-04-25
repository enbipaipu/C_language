#include <stdio.h>

void swap(double *x, double *y)
{
    double z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    double x = 1.0, y = 2.0;

    swap(&x, &y);

    printf("x = %lf, y = %lf\n", x, y);
    return 0;
}