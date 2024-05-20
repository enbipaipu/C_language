#include <stdio.h>
#include <string.h>

void KMP_table(const char *W, int *T)
{
    T[0] = -1;
    int j = -1;
    for (int i = 0; i < strlen(W); i++)
    {
        while (j >= 0 && T[i] != T[j])
        {
            j = T[j];
        }
        T[i + 1] = j + 1;
        j += 1;
    }
}

char *my_KMP(const char *haystack, const char *needle)
{
    const char *S = haystack;
    const char *W = needle;
    const char *head = 0;

    int i, j = 0;
    int T[(sizeof(haystack) / sizeof(char))];
    KMP_table(W, T);
    while (i + j <= (sizeof(S) / sizeof(char)))
    {
        printf("%d\n", j);
        if (S[i + j] == W[j])
        {
            j += 1;

            if (j == (sizeof(W) / sizeof(char)))
            {
                return (char *)&haystack[i];
            }
        }
        else
        {
            i = i + j - T[j];
            if (j > 0)
            {
                j = T[j];
            }
        }
    }

    return "NULL";
}

int main()
{
    char a[] = "abc";
    char b[] = "abc";

    printf("%c\n", a[0]);
    char *s = my_KMP(a, b);

    printf("%c\n", *s);
    return 0;
}