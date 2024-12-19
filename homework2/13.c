#include <stdio.h>

// 实现矩阵乘法的函数
void matrix_multi(int A[3][4],int B[4][5], int C[3][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 打印矩阵的函数
void printMatrix(int matrix[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int B[4][5] =
    {
        {1, 2, 3, 4, 5},
                                                       {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    double C[3][5];

    // 调用矩阵乘法函数
    matrix_multi(A, B, C);

    // 打印结果矩阵C
    printf("矩阵A与矩阵B相乘的结果矩阵C为：\n");
    printMatrix(C, 3);

    return 0;
}
