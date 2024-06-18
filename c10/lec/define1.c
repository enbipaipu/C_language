/* #define マクロ名 置き換える内容 */
#define PI 3.14159

double area(double r)
{
    return PI * r * r;
}

/* 下記のように解釈される */

double area(double r)
{
    return 3.14159 * r * r;
}