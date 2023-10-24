#include <stdio.h>

void Triangle(int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            printf("*");
        }
        for (j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int M, N, T;
	
    scanf("%d", &M);
    scanf("%d", &N);
    scanf("%d", &T);
	
    for (int k = 0; k < M; k++) {
        Triangle(N);
    }

    return 0;
}
