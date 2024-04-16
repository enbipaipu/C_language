#include <stdio.h>

int main()
{
    int x;
    printf("数を入力してください");
    scanf("%d", &x);
    if (x < 0)
    {
        x = -x;
    };

    printf("絶対値は%dです。\n", x);
    return 0;
}