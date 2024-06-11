/* GMPを利用する */

#include <gmp.h>

void factorial(mpz_t result, int n)
{
    int i;
    mpz_set_si(result, 1);
    for (i = 1; i <= n; i++)
    {
        mpz_mul_si(result, result, i);
    }
}

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        mpz_t result;
        mpz_init(result);
        factorial(result, i);
        gmp_printf("%d! = %Zd\n", i, result);
        mpz_clear(result);
    }
    return 0;
}