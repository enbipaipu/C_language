/* ex1 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x, y;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <number> <number>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);
    printf("%d + %d = %d\n", x, y, x + y);

    return 0;
}