#include <stdio.h>
#include <stdlib.h>

int isSudokuCorrect(int sudoku[9][9]) {

    for (int i = 0; i < 9; i++) {
        int rowCheck[9] = {0};
        int colCheck[9] = {0};
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] < 1 || sudoku[i][j] > 9 || sudoku[j][i] < 1 || sudoku[j][i] > 9) {
                return 0;
            }
            if (rowCheck[sudoku[i][j] - 1] == 1 || colCheck[sudoku[j][i] - 1] == 1) {
                return 0;
            }
            rowCheck[sudoku[i][j] - 1] = 1;
            colCheck[sudoku[j][i] - 1] = 1;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int subgridCheck[9] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (subgridCheck[sudoku[i + k][j + l] - 1] == 1) {
                        return 0;
                    }
                    subgridCheck[sudoku[i + k][j + l] - 1] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int T;
    scanf("%d", &T);

    int* isValid = (int*)malloc(T * sizeof(int));

    for (int t = 0; t < T; t++) {
        int sudoku[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        isValid[t] = isSudokuCorrect(sudoku);
    }

    for (int t = 0; t < T; t++) {
        printf("Case #%d: %s\n", t + 1, (isValid[t] ? "TRUE" : "FALSE"));
    }

    int correctSudokus = 0;
    for (int t = 0; t < T; t++) {
        if (isValid[t]) {
            correctSudokus++;
        }
    }

    float totalAccuracy = (float)correctSudokus / T * 100;
    printf("Total Accuracy: %.2f%%\n", totalAccuracy);

    free(isValid);
    return 0;
}
