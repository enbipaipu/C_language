#include <stdio.h>
#include <stdint.h>

/**
 * addressに格納されているdataのi bit目に1をセットする
 */
void setbit(uint32_t *address, int i)
{
    *address = (*address) | (1U << i);
}

/**
 * addressに格納されているdataのi bit目を0にクリアする
 */
void clearbit(uint32_t *address, int i)
{
    *address = (*address) & (~(1U << i));
}

int main()
{
    uint32_t x = 1;
    clearbit(&x, 0);
    printf("%d\n", x);
    return 0;
}