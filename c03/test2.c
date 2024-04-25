#include <stdio.h>

int x = 0;

int main()
{
    int x = 1;

    if (1)
    {
        int x = 2;
        x = x + 1;
    }

    printf("x = %d\n", x);
    return 0;
}