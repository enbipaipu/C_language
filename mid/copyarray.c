#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *copyarray(double *a, int n)
{
    double *s = (double *)malloc(sizeof(double) * n);

    for (int i = 0; i < 3; i++)
    {
        s[i] = a[i];
    }

    return s;
}

int main()
{
    double arr[] = {1.0, 2.0, 3.0};

    double *replica = copyarray(arr, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%f\n", replica[i]);
    }
    free(replica);
    return 0;
}