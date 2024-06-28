#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
        goto error;

    char buf[100];

    uint32_t x = 0x01;

    while (fgets(buf, sizeof(buf), fp))
    {

        for (int i = 0; i < (sizeof(buf) / sizeof(buf[0])); i++)
        {
            if (buf[i] == '\n')
                break;

            int t = buf[i];

            if (t >= 65 && t <= 90)
            {
                t += 32;
            }
            if (t >= 97 && t <= 122)
            {
                x = x | (0x01 << (t - 97));
            }
        }
    }
    x = ~x;
    printf("Unused chars: ");
    for (int i = 0; i < 26; i++)
    {
        if ((x >> i) & 1)
        {
            printf("%c", 97 + i);
        }
    }
    printf("\n");
    fclose(fp);
    return 0;

error:
    if (fp)
        fclose(fp);
    return 1;
}
