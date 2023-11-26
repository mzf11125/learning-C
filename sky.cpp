#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    char array[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &array[i][j]);  
        }
    }

   
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
