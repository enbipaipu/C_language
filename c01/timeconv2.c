#include <stdio.h>

int JST_to_EST(int jst)
{
    int est = jst - 14;
    if (est < 0)
    {
        est += 24;
    }
    return est;
}

int main()
{
    int hour;
    printf("今日本は何時(0-23)? ");
    scanf("%d", &hour);
    if (hour < 0 || hour > 23)
    {
        printf("エラー： 正しい時刻を入力してください\n");
        return 1;
    }
    printf("今ニューヨークは%d時です\n", JST_to_EST(hour));
    return 0;
}