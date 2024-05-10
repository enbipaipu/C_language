#include <stdio.h>

int main()
{
    int x[2][2];
    int A[][2] = {
        {1, 2},
        {3, 4},
    };
    int B[][2] = {
        {5, -6},
        {-7, 8},
    };
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            x[i][j] + B[i][j];
        }
    }
}