#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    printf("%d\n", MAX(2, 3));
    return 0;
}