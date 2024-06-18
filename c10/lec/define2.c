/* #define マクロ名(引数1, 引数2, ...) */
#define MUL(x, y) x *y

int main()
{
    int a = MUL(1, 2);
    double b = MUL(3.4, 5.6);
    ;
}

/* 下記のように解釈される */

int main()
{
    int a = 1 * 2;
    double b = 3.4 * 5.6;
    ;
}