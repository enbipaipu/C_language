#include <stdio.h>
#include <stdint.h>

// 0and0  1and1で一致していたら1

int equal_bits(uint8_t x, uint8_t y)
{
    int cnt = 0;
    uint32_t result = ~(x ^ y);
    for (int s = 0; s < 8; s++)
    {
        if (result & (1U << s))
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    printf("%d\n", equal_bits(75, 255));

    return 0;
}