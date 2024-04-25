#include <stdio.h>
int sigma(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += i;
    }
    return result;
}

int main()
{
    printf("%d\n", sigma(3));
    return 0;
}
