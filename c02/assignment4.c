#include <stdio.h>

int main()
{
    for (int s = 1; s < 10; s++)
    {

        for (int t = 1; t < 10; t++)
        {
            int a = s * t;
            printf("%5u", a);
        }
        printf("\n");
    }
    return 0;
}