#include <stdio.h>
#include <string.h>

int main()
{
    char s[5] = "Toyo";
    char t[20] = "INIAD";
    /* メモリの領域は５つ分になる */
    t[5] = ' ';
    memcpy(&t[6], s, 5);

    printf("%s\n", s);
    printf("%s\n", t);
    return 0;
}