#include <stdio.h>

int find_even(const int *a, const int len)
{
    for (int t = 0; t < len; t++)
    {
        if (a[t] % 2 == 0)
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

    printf("even elements in x? %s\n", (find_even(x, 4) ? "yes" : "no"));
    printf("even elements in y? %s\n", (find_even(y, 4) ? "yes" : "no"));

    return 0;
}