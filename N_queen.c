#include <stdio.h>
#include <stdbool.h>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j])
              printf("Q");
            else
              printf(".");
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        // All queens are placed successfully
        return true;
    }

    for (int i = 0; i < N; i++) {

        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            if(solveNQueensUtil(board, col + 1))
              return true;

            board[i][col] = 0;
        }
    }
    return false;

}

bool solveNQueens() {
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}