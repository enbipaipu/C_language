#include <stdio.h>
int main()
{
    int n, ans = 0;
    printf("整数値n= ");
    scanf("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        // ｃ言語では累乗演算子がない

        ans = x * x * x * x + ans;
    }
    printf("%d\n", ans);
    return 0;
}