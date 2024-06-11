#include <stdio.h>

// Ascending sort
void aSort(int *a, int *b)
{
    int tmp;
    /* 5. *a が *bより大きい場合は、値を交換する。 */
    if (*a >= *b)
    {
        tmp = *b;
        *b = *a;
        *a = tmp;
    }
}

int main()
{
    int x, y;

    printf("x = ");
    scanf("%d", &x);

    printf("y = ");
    scanf("%d", &y);

    aSort(&x, &y);
    printf("After asending sort: x = %d, y = %d \n", x, y);

    return 0;
}
