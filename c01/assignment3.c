#include <stdio.h>

int main()
{
    int X, Y, Z;
    int max;

    printf("X = ");
    scanf("%d", &X);
    printf("Y = ");
    scanf("%d", &Y);
    printf("Z = ");
    scanf("%d", &Z);

    max = X;
    if (Y > max)
    {
        max = Y;
    }
    if (Z > max)
    {
        max = Z;
    }
    printf("Maximum value is %d\n", max);

    return 0;
}