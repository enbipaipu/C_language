#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t x)
{
    int b[32];
    int t;
    for (t = 0; t < 32; t++)
    {
        b[t] = 0;
    }
    for (int i = 0; x > 0; i++)
    {
        b[i] = x % 2;
        x = x / 2;
    }

    while (t > 0)
        printf("%d", b[--t]);
    putchar('\n');
}

int main()
{
    union
    {
        float f;
        uint32_t u;
    } v;

    v.f = 256.5;
    printf("%d\n", v.u);
    print_binary(v.u);

    return 0;
}

/*
256.5をIEEE754単精度で表現してみる

まず、正の数なので符号は0
次に、256.5を2進数で表すと、100000000.1となる
小数点を左に移動させると、1.000000001 * (10 ** 8) となり、
正規化した浮動小数点数になった。
最後に、指数の8と32ビット IEEE 754 形式の127を足して、135となる。
135を2進数表記して10000111となる。
以上の3つ (0, 10000111, 1.000000001)をまとめると、
01000011100000000100000000000000となり、

c言語の浮動小数の表現がIEEE754の理論通りであると言える。
 */