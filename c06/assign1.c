#include <stdio.h>

typedef struct fraction
{
    int numer;
    int denom;
} fraction;

void fraction_mul(fraction *result, const fraction *someone, const fraction *someone2)
{
    (*result).numer = (*someone).numer * (*someone2).numer;

    (*result).denom = (*someone).denom * (*someone2).denom;
}

void fraction_print(const fraction *someone)
{
    printf("%d/%d\n", someone->numer, someone->denom);
}

int main()
{
    fraction a = {
        .numer = 7,
        .denom = 3,
    };
    fraction b = {
        .numer = 2,
        .denom = 5,
    };

    fraction result;

    fraction_mul(&result, &a, &b);
    fraction_print(&result);

    return 0;
}