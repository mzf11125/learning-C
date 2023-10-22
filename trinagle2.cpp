#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < N - j; k++) {
                printf(" ");
            }
            for (int k = 0; k < j; k++) {
                printf("*");
            }
            if(N != 1){
            	printf("\n");
			}
        }
    }

    return 0;
}
