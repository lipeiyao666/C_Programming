#include <stdio.h>

// 函数声明
int two_dim_array_access(int *x, int i, int j, int m, int n, int C);

int main() {
    // 定义一个二维数组
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 二维数组的行数和列数
    int rows = sizeof(array) / sizeof(array[0]);
    int cols = sizeof(array[0]) / sizeof(array[0][0]);

    // 获取二维数组首地址
    int *array_ptr = (int *)array;

    // 要访问的目标元素的下标
    int m = 1;
    int n = 2;

    // 调用函数访问目标元素
    int result = two_dim_array_access(array_ptr, m, n, rows, cols, cols);

    if (result == -1) {
        printf("访问失败，下标不合法。\n");
    } else {
        printf("访问到的元素值为: %d\n", result);
    }

    return 0;
}

// 函数定义
int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    // 首先进行下标合法性验证
    if (i < 0 || i >= m || j < 0 || j >= n) {
        // 如果下标不合法，返回一个特殊值表示访问失败，这里返回 -1
        return -1; }

    // 根据二维数组在内存中的存储方式（按行存储）来计算目标元素的地址
    int offset = i * C + j;

    // 通过计算得到的偏移量来访问目标元素
    return *(x + offset);
}
                          
