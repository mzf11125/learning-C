#include <stdio.h>

void drawRightTriangle(int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            printf("");
        }
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int M, N, T;

    scanf("%d", &M, &N);
    scanf("%d", &N);
    scanf("%d", &T);

    for (int k = 0; k < M; k++) {
        drawRightTriangle(N);
    }

    return 0;
}
