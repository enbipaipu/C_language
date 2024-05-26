#include <stdio.h>

void tail(const char *s)
{
    if (s[0] == '\0')
    {
        printf("\n");
    }
    else
    {
        const char *t = &s[1];
        printf("%s\n", t);
    }
}

int main()
{
    char s[] = "iniad";
    tail(s);

    tail("");
    return 0;
}