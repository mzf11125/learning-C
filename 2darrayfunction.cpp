#include <stdio.h>

void function(int N, int M, int Q){
    int array[200][200]= {0};
    for (int k = 0; k < Q; k++) {
        int X, Y, A;
        scanf("%d %d %d", &X, &Y, &A);
        array[X][Y] = A;
    }

    for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                printf("%d", array[i][j]);
                if(j < M - 1){
                    printf(" ");
                }
            }
        printf("\n");
    }
}

int main() {
    int N, M, Q;

    scanf("%d %d %d", &N, &M, &Q);
    function(N, M, Q);

    return 0;
}