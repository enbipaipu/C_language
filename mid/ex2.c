#include <stdio.h>
#include <string.h>

void vprint(char *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c\n", a[i]);
    }
}

int main()
{
    char a[] = "INIAD is wonderful";
    int n = strlen(a);
    vprint(a, n);
    return 0;
}