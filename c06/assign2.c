#include <stdio.h>

typedef struct fraction
{
    int numer;
    int denom;
} fraction;

void fraction_add(fraction *result, const fraction *someone, const fraction *someone2)
{
    int nu = ((*someone).numer * (*someone2).denom) + ((*someone).denom * (*someone2).numer);
    int de = (*someone).denom * (*someone2).denom;

    /* ユークリッドの互除法 */
    int a = nu;
    int b = de;
    int r = a % b;

    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    (*result).numer = nu / b;
    (*result).denom = de / b;
}

void fraction_print(const fraction *someone)
{
    printf("%d/%d\n", someone->numer, someone->denom);
}

int main()
{
    fraction a = {
        .numer = 1,
        .denom = 6,
    };
    fraction b = {
        .numer = 1,
        .denom = 6,
    };

    fraction result;

    fraction_add(&result, &a, &b);
    fraction_print(&result);

    return 0;
}