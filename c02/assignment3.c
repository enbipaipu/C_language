#include <stdio.h>

// n! = n * (n-1)!

int fib(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    int result = 1;
    result = n * fib(n - 1);
    printf("%d! = %d\n", n, result);
    return result;
}

int main()
{
    fib(50);
    return 0;
}