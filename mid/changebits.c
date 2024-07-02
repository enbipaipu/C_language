#include <stdio.h>
#include <stdint.h>

uint32_t flip13(uint32_t x)
{
    uint32_t y = ~((x) & (1 << 13));
    uint32_t y2 = (y) & (1 << 13);
    uint32_t z = (x) & (~(1 << 13));

    return y2 | z;
}

uint32_t Flip13(uint32_t x)
{
    uint32_t bit13 = x & (1U << 13); // x & 000010000000000 = 13bit目のみを取得
    uint32_t z = x & ~(1U << 13);    // x & 111101111111111 = 13bit目以外を取得

    return ~bit13 & z;
}

uint32_t FLip13(uint32_t x)
{
    uint32_t bit13 = x & ~(1U << 13);

    if (bit13)
    {
        return x & (1U << 13);
    }
    else
    {
        return x | (1U << 13);
    }
}
uint32_t FLIp13(uint32_t x)
{
    return x ^ (1U << 13);
}

int main()
{
    uint32_t v = 0xdeadbeef;
    printf("%u -> %u\n", v, Flip13(v));
    return 0;
}