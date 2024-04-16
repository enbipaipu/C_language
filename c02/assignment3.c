#include <stdio.h>

// n! = n * (n-1)!

int factorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    int result = 1;
    result = n * factorial(n - 1);
    printf("%d! = %d\n", n, result);
    return result;
}

int main()
{
    factorial(50);
    return 0;
}