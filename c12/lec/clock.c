#include <stdio.h>
#include <time.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    clock_t start, end;

    start = clock();
    fib(40);
    end = clock();

    printf("CPU Time: %f second\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}