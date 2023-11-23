#include <stdio.h>

int main() {
    int N, M, Q;

    scanf("%d %d %d", &N, &M, &Q);

    int array[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = 0;
        }
    }

    for (int k = 0; k < Q; k++) {
        int X, Y, A;
        scanf("%d %d %d", &X, &Y, &A);
        array[X][Y] = A;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}