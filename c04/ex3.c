#include <stdio.h>
void add_matrix(int x[2][2], int a[2][2], int b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            x[i][j] = a[i][j] + b[i][j];
        }
    }
}