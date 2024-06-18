#include <stdio.h>

#define DEBUG 1

int main()
{
    int i, sum;
    for (i = 0, sum = 0; i < 5; i++)
    {
        sum += i;
#if DEBUG
        fprintf(stderr, "i = %d, sum = %d\n", i, sum);
#endif
    }
    printf("result = %d\n", sum);
    return 0;
}