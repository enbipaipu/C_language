#include <stdio.h>

int pyramid(int a)
{
    FILE *fp = fopen("pyramid.txt", "w");
    if (!fp)
    {
        goto error;
    }

    for (int s = 1; s < a + 1; s++)
    {
        for (int i = 0; i < a - s; i++)
        {
            fprintf(fp, " ");
        }
        for (int i = 0; i < 2 * s - 1; i++)
        {
            fprintf(fp, "#");
        }

        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;

error:
    if (fp)
        fclose(fp);
    return 1;
}

int main()
{
    pyramid(5);
    return 0;
}