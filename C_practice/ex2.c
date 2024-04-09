#include <stdio.h>

int* add(int x , int y )
{
    int z = x + y;
    return &z;
}

int main()
{
    int *p = add(2, 3);
    printf("2 + 3 = %d\n", *p);
    return 0;
}