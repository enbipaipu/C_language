#include <stdio.h>

void getData(int data[3])
{
    data[0] = 10;
    data[1] = 11;
    data[2] = 12;
}

int main()
{
    int a[3];
    getData(a);
    printf("%d, %d, %d, \n", a[0], a[1], a[2]);
    return 0;
}