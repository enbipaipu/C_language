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

void bigint_set_int(bigint *d, int v)
{
    int count = 0;
    while (v > 0)
    {

        digint *t = (digint *)malloc(sizeof(digint));

        int a = v % 10000;
        t->x = a;
        d->digints[count] = t;

        v = v / 10000;
        count += 1;
    }
    d->n = count;
}

void bigint_add(bigint *d, bigint *a)
{
    int i;
    int carry = 0;
    int max_n = (d->n > a->n) ? d->n : a->n;

    for (i = 0; i < max_n || carry; i++)
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
    d->n = i;
}

void bigint_mul(bigint *d, bigint *a)
{
    /* d*=a を行う */
}

void bigint_print(bigint *d)
{

    for (int t = d->n - 1; t >= 0; t -= 1)
    {
        printf("%d", d->digints[t]->x);
    }
    printf("\n");
}

int main()
{
    int x = 22222222;
    bigint *d = (bigint *)malloc(sizeof(bigint));
    if (d == NULL)
    {
        fprintf(stderr, "Memory allocation failed for bigint\n");
        return 1;
    }

    bigint_set_int(d, x);
    bigint_print(d);

    bigint *e = (bigint *)malloc(sizeof(bigint));
    bigint_set_int(e, 88888888);
    bigint_print(e);

    printf("Add: ");
    bigint_add(d, e);
    bigint_print(d);

    bigint_set_int(d, x);
    printf("Mul: ");
    bigint_mul(d, e);
    bigint_print(d);
    return 0;
}
