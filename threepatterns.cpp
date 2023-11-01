#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i % K == 0) {// 0 1 2 3 4 5 6 7 8 9
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j % K == 0) { 
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}
