#include <stdio.h>

void add_vector(const int *a, const int *b, int *p)
{

    for (int t = 0; t < 3; t++)
    {
        p[t] = a[t] + b[t];
    }
}

int main()
{
    int x[] = {1, -2, 3};
    int y[] = {-3, 4, 5};

    int p[3];
    add_vector(x, y, p);

    printf("%d %d %d\n", p[0], p[1], p[2]);
    return 0;
}