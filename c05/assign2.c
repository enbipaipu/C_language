#include <stdio.h>
#include <string.h>

void interleave(char *d, const char *a, const char *b)
{
    int A = strlen(a);
    int B = strlen(b);
    int len_max = A;
    int len_min = B;

    if (A <= B)
    {
        len_max = B;
        len_min = A;
    }

    for (int s = 0; s < len_min; s++)
    {
        int t = s * 2;
        d[t] = a[s];
        d[t + 1] = b[s];
    }

    for (int s = len_min * 2; s < len_max + len_min; s++)
    {
        int t = s - len_min;
        if (A <= B)
        {
            d[s] = b[t];
        }
        else
        {
            d[s] = a[t];
        }
    }
}

int main()
{
    char d[20], z[20];
    char a[] = "Toyo";
    char b[] = "University";
    char c[] = "INIAD";

    interleave(z, c, a);
    printf("%s\n", z);

    interleave(d, a, b);
    printf("%s\n", d);

    return 0;
}