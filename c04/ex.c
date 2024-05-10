#include <stdio.h>

int main()
{

    int x, y, *p, *q;
    x = 12345;
    printf("%d\n", x);
    p = &x;
    printf("%p\n", p);
    q = p;
    printf("%p\n", p);
    y = *q;
    printf("%d\n", y);

    return 0;
}