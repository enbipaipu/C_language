#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int X;
    int Y;
    printf("X = ");
    scanf("%d", &X);
    printf("Y = ");
    scanf("%d", &Y);
    printf("X + Y = %d + %d = %d\n", X, Y, sum(X, Y));
}