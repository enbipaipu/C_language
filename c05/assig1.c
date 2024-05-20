#include <stdio.h>

void pyramid(int a)
{
    for (int s = 1; s < a + 1; s++)
    {
        for (int i = 0; i < a - s; i++)
        {
            printf("%s", " ");
        }
        for (int i = 0; i < 2 * s; i++)
        {
            printf("%s", "#");
        }

        printf("\n");
    }
}

int main()
{
    pyramid(5);
    return 0;
}