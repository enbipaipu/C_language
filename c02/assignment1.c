#include <stdio.h>

int main()
{
    int x, ans = 0;
    printf("X= ");
    scanf("%d", &x);
    if (x <= 0)
    {
        printf("ERROR 正の整数を入力してください\n");
        return 1;
    }
    while (x >= 1)
    {
        x = x / 10;
        ans += 1;
    }

    printf("The number of digits of X is %d\n", ans);
    return 0;
}