#include <stdio.h>

#define SWAP(x, y)   \
    do               \
    {                \
        int tmp = y; \
        y = x;       \
        x = tmp;     \
    } while (0)

int main()
{
    int a = 1, b = 2;
    SWAP(a, b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}