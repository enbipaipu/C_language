#include <stdio.h>

static int even(int element)
{
    return (element % 2) == 0;
}

int find(const int *a, const int len, int (*cond)(int))
{
    for (int t = 0; t < len; t++)
    {
        if (cond(a[t]))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int x[] = {1, 3, 5, 7};
    int y[] = {1, 3, 6, 9};

    printf("even elements in x? %s\n", (find(x, 4, even) ? "yes" : "no"));
    printf("even elements in y? %s\n", (find(y, 4, even) ? "yes" : "no"));

    return 0;
}