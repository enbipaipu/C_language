#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("search.c", "r");
    if (!fp)
    {
        printf("ERROR: failed to open file\n");
        return 1;
    }
    int line = 0;
    char buf[128];
    while (fgets(buf, sizeof(buf), fp))
    {
        line++;
        if (strstr(buf, "int"))
        {
            printf("%d:%s", line, buf);
        }
    }
    return 0;
}