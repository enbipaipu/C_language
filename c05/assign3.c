#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdupcat(char s[], char t[])
{
    int memory = strlen(s) + strlen(t);
    char *T = (char *)malloc(memory + 2);

    strcpy(T, s);
    strcat(T, t);
    return T;
}

int main()
{
    char *s = strdupcat("INIAD", "Toyo");
    s[5] = 'Y';
    printf("%s\n", s);
    free(s);
    return 0;
}