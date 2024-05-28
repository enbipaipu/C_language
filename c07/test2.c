#include <stdio.h>

void halfadder(int a, int b, int *s, int *c)
{
    *s = 0;
    *c = 0;
    if (a + b == 2)
    {
        *c = 1;
    }
    else if (a + b == 1)
    {
        *s = 1;
    }
}

int main()
{
    int a = 0;
    int b = 0;
    int s, c;

    halfadder(a, b, &s, &c);
    printf("s:%d c:%d\n", s, c);
    a = 0;
    b = 1;

    halfadder(a, b, &s, &c);
    printf("s:%d c:%d\n", s, c);
    a = 1;
    b = 0;

    halfadder(a, b, &s, &c);
    printf("s:%d c:%d\n", s, c);
    a = 1;
    b = 1;

    halfadder(a, b, &s, &c);
    printf("s:%d c:%d\n", s, c);
    return 0;
}