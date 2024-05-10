#include <stdio.h>

void round100(unsigned int *p)
{
    unsigned int t = *p;
    t /= 100;

    if (*p % 100 >= 50)
    {
        t++;
    }

    t = t * 100;

    *p = t;
}

int main()
{
    unsigned int n = 12355;
    printf("%u\n", n);
    round100(&n);
    printf("%u\n", n);
    return 0;
}