#include <stdio.h>
int main(void)
    {int Gx_Matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        Gx_Matrix[i][1] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        Gx_Matrix[i][0] = -1;
    }
    Gx_Matrix[1][0] = -2;
    for (int i = 0; i < 3; i++)
    {
        Gx_Matrix[i][2] = 1;
    }
    Gx_Matrix[1][2] = 2;

    // Creating Gy matrix
    int Gy_Matrix[3][3];
    for (int j = 0; j < 3; j++)
    {
        Gy_Matrix[1][j] = 0;
    }
    for (int j = 0; j < 3; j++)
    {
        Gy_Matrix[0][j] = -1;
    }
    Gy_Matrix[0][1] = -2;
    for (int j = 0; j < 3; j++)
    {
        Gy_Matrix[2][j] = 1;
    }
    Gy_Matrix[2][1] = 2;
    // Testing the correctness of Gx and Gy
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", Gx_Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", Gy_Matrix[i][j]);
        }
        printf("\n");
    }
    }
