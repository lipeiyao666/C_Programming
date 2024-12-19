#include <stdio.h>

#define ROWS 3
#define COLS 4

int two_dim_array_access(int *x, int i, int j, int m, int n, int C);

int main() {
    int A[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 测试访问不同位置的元素
    int result1 = two_dim_array_access((int *)A, 0, 0, 1, 2, COLS);
    int result2 = two_dim_array_access((int *)&A[0][1], 0, 1, 2, 3, COLS);

    printf("two_dim_array_access((int *)A, 0, 0, 1, 2, COLS) 的返回值: %d\n", result1);
    printf("two_dim_array_access((int *)&A[0][1], 0, 1, 2, 3, COLS) 的返回值: %d\n", result2);

    return 0;
}
int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    int offset = (m - i) * C + (n - j);
    return *(x + offset);
}
