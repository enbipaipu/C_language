#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || strcmp(argv[1], "-C") != 0)
    {
        printf("適切なオプションを指定してください\n");
        return 1;
    }

    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL)
    {
        perror("ファイルを開くことができませんでした");
        return 1;
    }

    int i, identicalLines = 0;
    unsigned long offset = 0;
    char buf[16], prev_buf[16] = {0}, str[17], dump[49];
    size_t bytesRead;

    while ((bytesRead = fread(buf, sizeof(char), 16, fp)) > 0)
    {
        int identical = (identicalLines > 0 && memcmp(buf, prev_buf, 16) == 0);

        if (!identical)
        {
            if (identicalLines > 1)
            {
                printf("*\n");
            }

            str[0] = '\0';
            dump[0] = '\0';

            for (i = 0; i < bytesRead; i++)
            {
                char hex[4];
                snprintf(hex, sizeof(hex), "%02x ", (unsigned char)buf[i]);
                strcat(dump, hex);
                if (i == 7)
                {
                    strcat(dump, " ");
                }

                if (!isprint((unsigned char)buf[i]))
                {
                    strcat(str, ".");
                }
                else
                {
                    char s[2] = {buf[i], '\0'};
                    strcat(str, s);
                }
            }

            str[16] = '\0';

            printf("%08lx  %-48s |%s|\n", offset, dump, str);
        }

        if (identical)
        {
            identicalLines++;
        }
        else
        {
            identicalLines = 1;
        }

        memcpy(prev_buf, buf, 16);
        offset += bytesRead;
    }

    if (identicalLines > 1)
    {
        printf("*\n");
    }

    fclose(fp);
    return 0;
}