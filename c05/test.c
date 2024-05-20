#include <stdio.h>

int find_zero(int *a, int n)
{
    for (int s = 0; s < n; s++)
    {
        if (a[s] == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a[3] = {4, 0, 6};
    int x = find_zero(a, 3);
    printf("%d\n", x);
    return 0;
}