#include <stdio.h>

int max(int a, int b, int c, int d, int e, int *idx)
{

    int max = a, max_idx = 1;

    if (max > b)
    {
        max = b;
        max_idx = 2;
    }
    if (c > max)
    {
        max = c;
        max_idx = 3;
    }
    if (d > max)
    {
        max = d;
        max_idx = 4;
    }
    if (e > max)
    {
        max = e;
        max_idx = 5;
    }

    if (idx != NULL)
    {
        *idx = max_idx;
    }
    return max;
}

int main()
{
    int n;

    printf("%d", max(10, 30, 50, 40, 20, &n));
    printf(" (n = %d)\n", n);
    return 0;
}