#include <stdio.h>
#include <stdlib.h>

// 棋盘大小定义
#define BOARD_SIZE 3

// 棋盘结构体
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} TicTacToeBoard;

// 初始化棋盘
void initBoard(TicTacToeBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] =' '; // 修正为单引号括起来的空格字符
        }
    }
}

// 打印棋盘
void printBoard(TicTacToeBoard *board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

// 检查是否有玩家获胜
int checkWin(TicTacToeBoard *board, char player) {
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        int win = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {  int win = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }

    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++) {
        int win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board->board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }

    // 检查对角线
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) return 1;
    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) return 1;

    return 0;
}

// 井字棋游戏主函数
void ticTacToeGame() {
    TicTacToeBoard board;
    initBoard(&board);
    char currentPlayer = 'X';
    int moves = 0;

    while (1) {
        printBoard(&board);
        int row, col;
        printf("玩家 %c 请输入行和列（例如：0 0）: ", currentPlayer);
                                                                       scanf("%d %d", &row, &col);

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board.board[row][col]!= ' ') { // 修正为单引号括起来的空格字符
            printf("无效的移动，请重新输入！\n");
            continue;
        }

        board.board[row][col] = currentPlayer;
        moves++;

        if (checkWin(&board, currentPlayer)) {
            printBoard(&board);
            printf("玩家 %c 获胜！\n", currentPlayer);
            break;
        } else if (moves == BOARD_SIZE * BOARD_SIZE) {
            printBoard(&board);
            printf("平局！\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
    }
}

// 五子棋棋盘结构体
typedef struct {
    char board[15][15];
} GomokuBoard;

// 初始化五子棋棋盘
void initGomokuBoard(GomokuBoard *board) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board->board[i][j] =' '; // 修正为单引号括起来的空格字符
        }
    }
}

// 打印五子棋棋盘
void printGomokuBoard(GomokuBoard *board) {
    printf("  ");
    for (int i = 0; i < 15; i++) {  printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", i);
        for (int j = 0; j < 15; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

// 检查五子棋是否有玩家获胜
int checkGomokuWin(GomokuBoard *board, char player) {
    // 检查水平方向
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= 15 - 5; j++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board->board[i][j + k] == player) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == 5) return 1;
        }
    }

    // 检查垂直方向
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i <= 15 - 5; i++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board->board[i + k][j] == player) {
                    count++;
                } else {
                    break;if (row < 0 || row >= 15 || col < 0 || col >= 15 || board.board[row][col]!= ' ') { // 修正为单引号括起来的空格字符
            printf("无效的移动，请重新输入！\n");
            continue;
        }

        board.board[row][col] = currentPlayer;
        moves++;

        if (checkGomokuWin(&board, currentPlayer)) {
            printGomokuBoard(&board);
            printf("玩家 %c 获胜！\n", currentPlayer);
            break;
        } else if (moves == 15 * 15) {
            printGomokuBoard(&board);
            printf("平局！\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
    }
}

int main() {
    int choice;
    printf("选择游戏：\n");
    printf("1. 井字棋\n");
    printf("2. 五子棋\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ticTacToeGame();
            break;
        case 2:
            gomokuGame();
            break;
        default:
            printf("无效的选择！\n");
    }

    return 0;
}
