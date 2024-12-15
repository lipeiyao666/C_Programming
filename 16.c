#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check for five in a row, column, or diagonal
    // This is a simplified version and does not cover all cases
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {             if (board[i][j] == player && (i + 4 < SIZE && j + 4 < SIZE && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player && board[i+4][j+4] == player)) {
                return 1;
            }
        }
    }
    return 0;
}

int isFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    do {
        printf("Enter row and column for %c: ", player);
        scanf("%d %d", &row, &col);  } while (board[row][col] != ' ');
    board[row][col] = player;
}

int computerMove(char board[SIZE][SIZE], char player) {
    // Simple AI: Just pick the first available spot
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char board[SIZE][SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X', comp = 'O';

    while (1) {
        printBoard(board);
        playerMove(board, player);}
}
