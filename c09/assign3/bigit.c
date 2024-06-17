#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
} digint;

typedef struct
{
    int n;
    digint *digints[100];
} bigint;

void bigint_set_int(bigint *big, int v)
{
    int count = 0;
    while (v / 10000 > 0)
    {

        digint *t = (digint *)malloc(sizeof(digint));

        int a = v % 10000;
        t->x = a;
        big->digints[count] = t;

        v = v / 10000;
        count += 1;
    }
    big->n = count;
}

void bigint_add(bigint *d, bigint *a)
{
    int carry = 0;
    int max_n = (d->n > a->n) ? d->n : a->n;

    for (int i = 0; i < max_n || carry; i++)
    {
        if (i >= d->n)
        {
            d->digints[i] = (digint *)malloc(sizeof(digint));
            d->digints[i]->x = 0;
            d->n++;
        }

        if (i < a->n)
        {
            d->digints[i]->x += a->digints[i]->x + carry;
        }
        else
        {
            d->digints[i]->x += carry;
        }

        carry = d->digints[i]->x / 10000;
        d->digints[i]->x %= 10000;
    }
}

void bigint_mul(bigint *d, bigint *a)
{
    bigint result;
    result.n = 0;
    for (int i = 0; i < 100; i++)
        result.digints[i] = NULL;

    for (int i = 0; i < d->n; i++)
    {
        bigint temp;
        temp.n = 0;
        for (int j = 0; j < 100; j++)
            temp.digints[j] = NULL;

        int carry = 0;
        for (int j = 0; j < a->n || carry; j++)
        {
            if (j + i >= temp.n)
            {
                temp.digints[j + i] = (digint *)malloc(sizeof(digint));
                temp.digints[j + i]->x = 0;
                temp.n = j + i + 1;
            }

            long long mul_res = carry;
            if (j < a->n)
            {
                mul_res += (long long)d->digints[i]->x * a->digints[j]->x;
            }

            carry = mul_res / 10000;
            temp.digints[j + i]->x = mul_res % 10000;
        }

        if (temp.n >= result.n)
            result.n = temp.n;
        bigint_add(&result, &temp);

        for (int j = 0; j < temp.n; j++)
        {
            free(temp.digints[j]);
        }
    }

    for (int i = 0; i < d->n; i++)
    {
        free(d->digints[i]);
    }

    *d = result;
}

void bigint_print(bigint *d)
{
    printf("%d", d->digints[d->n - 1]->x);
    for (int t = d->n - 1; t >= 0; t -= 1)
    {
        printf("%d", d->digints[t]->x);
    }
    printf("\n");
}

int main()
{
    int x = 11111111;
    bigint *d = (bigint *)malloc(sizeof(bigint));
    if (d == NULL)
    {
        fprintf(stderr, "Memory allocation failed for bigint\n");
        return 1;
    }

    bigint_set_int(d, x);
    bigint_print(d);

    bigint *e = (bigint *)malloc(sizeof(bigint));
    bigint_set_int(e, 99999999);
    bigint_print(e);

    printf("Addition: ");
    bigint_add(d, e);
    bigint_print(d);

    bigint_set_int(d, x);
    printf("Multiplication: ");
    bigint_mul(d, e);
    bigint_print(d);
    return 0;
}
