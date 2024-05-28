#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;
    char s[100];

    now = time(NULL); /* time(&now) でも可。nowにUNIX時刻を代入*/

    ctime_r(&now, s); /* sのメモリ領域にnowの文字列データを書き込む */
    printf("current time : %s\n", s);

    return 0;
}