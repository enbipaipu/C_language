#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        perror("fopen");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (islower(c))
        {
            putchar(toupper(c)); // 小文字->大文字
        }
        else
        {
            putchar(tolower(c)); // 大文字->小文字
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}