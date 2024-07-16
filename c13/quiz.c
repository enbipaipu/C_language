#include <stdio.h>
#include <math.h>

double quadeq(double a, double b, double c, double *x2)
{
    double d = b * b - 4 * a * c;
    double ds = sqrt(d);

    if (x2 != NULL)
    {
        *x2 = (-b - ds) / (2 * a);
    }

    return (-b + ds) / (2 * a);
}
int main()
{
    double a, b, c;
    double x1, x2;
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);
    x1 = quadeq(a, b, c, &x2);
    printf("x = %f, %f\n", x1, x2);
    return 0;
}