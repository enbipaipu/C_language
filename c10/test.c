#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (int s = 0; s < atoi(argv[2]); s++)
    {
        printf("%s\n", argv[1]);
    }
    return 0;
}