#include <stdio.h>

void Triangle(int N, int T) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            printf("*");
        }
        for (j = 0; j < T; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int M, N, T;
    scanf("%d", &T);
    for(int m = 0; m < T; m++){
    	scanf("%d", &M);
    	scanf("%d", &N);
    	for (int k = 0; k < M; k++) {
    	printf("Case #%d: ", k+1);
        Triangle(N, T);
    	}		
	}
    
    return 0;
}
