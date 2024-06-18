#include <stdio.h>

#define DEBUG 0

#if DEBUG
#define DP(fmt, ...)

#else
#define DP(dmt, ...)

#endif

int main()
{
    int i, sum;
    for (i = 0, sum = 0; i < 5; i++)
    {
        DP("i = %d, sum = %d\n", i, sum);
        sum += i;
        DP("i = %d, sum = %d\n", i, sum);
    }
    printf("result = %d\n", sum);
    return 0;
}