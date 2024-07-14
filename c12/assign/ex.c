#include <stdio.h>

int main()
{
    FILE *fp = fopen("diary.bin", "wb");
    char st[] = {"         Hello, INIAD!\nHow are you\n"};
    fwrite(st, sizeof(st), sizeof(char), fp);
    fclose(fp);
    return 0;
}