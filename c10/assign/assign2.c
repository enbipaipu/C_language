
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char buf[128];
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        perror("ERROR");
        return 1;
    }
    while (fgets(buf, sizeof(buf), fp))
    {
        if (buf[0] != '\n')
        {
            printf("%s", buf);
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}