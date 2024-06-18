#include <stdio.h>
#include <stdlib.h>

typedef struct hoge
{
    int fuga;
} HOGE;

typedef struct foo
{
    HOGE *ppiyo;
} FOO;

/* int main(void)
{
    HOGE piyo;
    piyo.fuga = 3;
} */

/* int main(void)
{
    HOGE *ppiyo;
    ppiyo = (HOGE *)malloc(sizeof(HOGE));
    ppiyo->fuga = 3;
} */

int main(void)
{
    FOO bar;
    bar.ppiyo = (FOO *)malloc(sizeof(HOGE));
    bar.ppiyo->fuga = 3;
}