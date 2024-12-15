#include <stdio.h>

#define ROWS 3
#define COLS 4

void printArray(int arr[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("原始二维数组：\n");
    printArray(arr);

    // 将二维数组元素按顺序存入一维数组，模拟内存镜像
    int mirrorArray[ROWS * COLS];
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mirrorArray[index++] = arr[i][j];
        }
    }

    printf("模拟内存镜像的一维数组：\n");
    for (int i = 0; i < ROWS * COLS; i++) {
        printf("%d ", mirrorArray[i]);
    }
    printf("\n");

    return 0;
}
