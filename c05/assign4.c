#include <stdio.h>
#include <string.h>

char *my_strstr(const char *haystack, const char *needle)
{

    for (int s = 0; s < strlen(haystack); s++)
    {
        for (int t = 0; t < strlen(needle); t++)
        {
            if (haystack[s + t] == needle[t])
            {

                if (t == strlen(needle) - 1)
                {
                    return (char *)&haystack[s];
                }

                continue;
            }
            break;
        }
    }

    return "NULL";
}

int main()
{
    char a[] = "abababc";
    char b[] = "ababc";
    char *s = my_strstr(a, b);
    printf("%c\n", a[2]);
    printf("%c\n", *s);
    return 0;
}