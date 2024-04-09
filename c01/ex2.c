#include <stdio.h>
#include <unistd.h>

int main()
{
    int n;
    printf("second = ");
    scanf("%d", &n);
    while (n > 0)
    {
        printf("%d\n", n);
        sleep(1);
        n -= 1;
    }
    printf("finished\n");
    return 0;
}