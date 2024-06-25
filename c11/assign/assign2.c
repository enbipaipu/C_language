#include <stdio.h>
#include <stdint.h>

uint32_t rotate_left(uint32_t x, int n)
{
    return (x << n) | (x >> (32 - n));
}

int main()
{
    uint32_t x = 0x12345678;

    int n = 4;
    uint32_t y = rotate_left(x, n);
    printf("%x\n", y);
    return 0;
}