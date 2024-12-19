#include <stdio.h>

#define N 8

// 检查在当前位置 (row, col) 是否可以放置皇后
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 检查同一列是否有皇后
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // 检查左上方对角线是否有皇后
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // 检查右上方对角线是否有皇后
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// 递归函数用于放置皇后并找到所有解决方案
void solveNQueens(int board[N][N], int row) {
    // 如果已经放置了所有8个皇后，打印解决方案
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    printf("Q ");
                } else {
                    printf(". ");            }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[N][N] = {0};

    solveNQueens(board, 0);

    return 0;
}
