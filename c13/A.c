#include <stdio.h>

int main()
{
    char s[4];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'R')
        {
            printf("Yes\n");
            break;
        }
        else if (s[i] == 'M')
        {
            printf("No\n");
            break;
        }
    }

    return 0;
}