#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    const char *s = "01234567abcdef";
    char a[10], b[10] = "hello";
    if (strlen(s) >= sizeof(a))
        abort();
    strcpy(a, s);
    printf("b = %s\n", b);
    return 0;
}