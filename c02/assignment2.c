#include <stdio.h>

double power(double x, int n)
{
    double result = 1;
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    for (int i = 1; i <= n; i++)
    {
        result = result * x;
    }
    return result;
}

int main()
{
    double x, ans;
    int n;
    printf("x= ");
    scanf("%lf", &x);
    printf("n= ");
    scanf("%d", &n);

    ans = power(x, n);

    printf("x ** n = %lf\n", ans);
    return 0;
}