#include <stdint.h>
#include <stdio.h>
int main()
{
    uint32_t x = 1234567;
    uint32_t y = (x >> 4) & 10;
    printf("%d\n", y);
}