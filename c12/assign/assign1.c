#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shuffle(void *arr, size_t size, size_t n)
{
    char *a = (char *)arr;

    for (int i = n - 1; i >= 1; i -= 1)
    {
        int j = rand() % i;

        char *arr_i = &a[i * size];
        char *arr_j = &a[j * size];
        if (*arr_i == '\n')
            continue;

        char tmp[size];
        memcpy(tmp, arr_j, size);
        memcpy(arr_j, arr_i, size);
        memcpy(arr_i, tmp, size);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        perror("fopen");
        return 1;
    }
    char buf[100];
    while (fgets(buf, sizeof(buf), fp))
    {
        int n;
        for (n = 0; buf[n] != '\0'; n++)
            ;
        shuffle(buf, sizeof(char), n);
        printf("%s", buf);
    }
    printf("\n");
    return 0;
}