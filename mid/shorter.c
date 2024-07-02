#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char s[20];
    strcpy(s, argv[1]);

    if (strlen(argv[2]) < strlen(argv[1]))
    {
        strcpy(s, argv[2]);
    }

    printf("%s\n", s);
    return 0;
}