#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, is_Entry = 1;
    scanf("%d", &n);
    char A[n + 2];
    scanf("%s", A);

    for (int i = 0; i < n; i++)
    {
        printf("%c ", A[i]);
        int num = atoi(A[i]);
        if (num % 2 != 0)
            continue;
        if (num % 3 != 0 && num % 5 != 0)
        {
            is_Entry = 0;
            break;
        }
    }
    printf("%s\n", (is_Entry == 1) ? "APPROVED" : "DENIED");

    return 0;
}