#include <stdio.h>
#include <stdlib.h>

// 计算一行字符的ASCII码之和
int rowSum(char row[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += row[i];
    }
    return sum;
}

// 交换两行字符数组
void swapRows(char A[][6], int row1, int row2) {
    char temp[6];
    for (int i = 0; i < 6; i++) {
        temp[i] = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = temp[i];
    }
}

// 对二维数组的每一行进行冒泡排序
void sortRows(char A[][6]) {
    int numRows = sizeof(A) / sizeof(A[0]);

    // 先根据行的ASCII码和进行排序
    for (int i = 0; i < numRows - 1; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            if (rowSum(A[j], 6) > rowSum(A[j + 1], 6)) {
                swapRows(A, j, j + 1);
            }
        }
    }

    // 再对每一行内部的字符进行排序
    for (int k = 0; k < numRows; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (A[k][i] > A[k][j]) {
                    char temp = A[k][i];
                    A[k][i] = A[k][j];  char temp = A[k][i];
                    A[k][i] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }
    }
}

int main() {
    char A[][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };

    sortRows(A);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        for (int j = 0; j < sizeof(A[0]) / sizeof(A[0][0]); j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}}
