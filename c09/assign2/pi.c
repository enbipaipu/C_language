/*
    $ gcc -Wall pi.c -lgmp -o pi
    $ ./pi
*/

#include <stdio.h>
#include <gmp.h>

int main()
{
    /* Set precision to 1000 bits */
    mpf_set_default_prec(10000);

    mpf_t ans, deno, y;

    mpf_init(ans);

    mpf_set_si(ans, 0);

    for (int n = 1; n < 50000; n++)
    {
        /* 分母の初期化と計算  16 * n * (n - 1) + 3 */
        mpf_init(deno);
        mpf_init(y);

        mpf_set_si(deno, 16);

        mpf_mul_ui(deno, deno, n);

        mpf_mul_ui(deno, deno, n - 1);

        mpf_add_ui(deno, deno, 3);

        /* 分子/分母 y = 2 / (16 * n * (n - 1) + 3 */
        mpf_ui_div(y, 2, deno);

        /* ans += y */
        mpf_add(ans, ans, y);

        mpf_clear(deno);
        mpf_clear(y);
    }

    mpf_mul_ui(ans, ans, 4);

    gmp_printf("円周率: %.1000Ff\n", ans);

    mpf_clear(ans);

    return 0;
}
