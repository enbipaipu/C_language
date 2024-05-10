#include <stdio.h>

int main()
{

    int n = 1000;
    int a[n + 1];
    a[0] = 0;
    a[1] = 0;
    for (int t = 2; t <= n; t++)
    {
        a[t] = 1;
    }

    for (int t = 2; t <= n; t++)
    {
        int x = a[t];
        if (x == 1)
        {
            for (int s = 2; s <= (n / t); s++)
            {
                a[t * s] = 0;
            }
        }
    }
    printf("Primzahlen: { ");
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == 1)
        {
            printf("%d, ", i);
        }
    }
    printf("}\n");

    return 0;
}