#include <string.h>
#include <stdio.h>

int my_strlen(char *st)
{
    int count;
    for (count = 0; st[count] != '\0'; count++)
    {
        ; /* 何もしない */
    }
    return count;
}
int main()
{
    char s[] = "INIAD";
    int x = my_strlen(s);
    printf("%d\n", x);
    return 0;
}