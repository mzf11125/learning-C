#include <stdio.h>

void initializeArray(int N, int M, int array[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = 0;
        }
    }
}

void processQueries(int Q, int N, int M, int array[N][M], int queries[Q][3]) {
    for (int k = 0; k < Q; k++) {
        int X = queries[k][0];
        int Y = queries[k][1];
        int A = queries[k][2];
        if (X < N && Y < M) {
            array[X][Y] = A;
        }
    }
}

void printArray(int N, int M, int array[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    int array[N][M];
    initializeArray(N, M, array);

    int queries[Q][3];
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    processQueries(Q, N, M, array, queries);

    printArray(N, M, array);

    return 0;
}