#include <stdio.h>
#include <stdbool.h>

#define N 9
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                printf(" | ");
            printf("%d ", grid[row][col]);
        }
        if (row == 2 || row == 5) {
            printf("\n");
            for (int i = 0; i < N; i++)
                printf("---");
        }
        printf("\n");
    }
}
bool isValid(int grid[N][N], int row, int col, int num) {
    
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }

    
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }

    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}
bool isGridFull(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                return false;
        }
    }
    return true;
}
void playSudoku(int grid[N][N]) {
    int row, col, num;
    while (!isGridFull(grid)) {
        printGrid(grid);
        printf("Enter row (0-8), column (0-8), and number (1-9) to fill (separated by space): ");
        scanf("%d %d %d", &row, &col, &num);

        if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > 9) {
            printf("Invalid input! Please enter numbers within range.\n");
            continue;
        }

        if (grid[row][col] != 0) {
            printf("Cell already filled! Choose another cell.\n");
        } else if (!isValid(grid, row, col, num)) {
            printf("Invalid move! Number can't be placed here.\n");
        } else {
            grid[row][col] = num;
        }
    }
    printf("Congratulations! You completed the Sudoku.\n");
}
int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Welcome to the Sudoku Game!\n");
    playSudoku(grid);

    return 0;
}