#include <stdio.h>
#include <string.h>

void interleave(char *d, const char *a, const char *b)
{
    int A = strlen(a);
    int B = strlen(b);
    int len_max = A;
    int len_min = B;
    int i = 0;
    if (A <= B)
    {
        len_max = B;
        len_min = A;
    }

    while (i / 2 < len_min)
    {
        d[i] = a[i / 2];
        i++;
        d[i] = b[i / 2];
        i++;
    }
    while (i < len_max + len_min)
    {
        int t = i - len_min;
        if (A <= B)
        {
            d[i] = b[t];
        }
        else
        {
            d[i] = a[t];
        }
        i++;
    }
    d[i] = '\0';
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