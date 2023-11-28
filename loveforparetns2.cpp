#include <stdio.h>

int main() {
    int N, Q;

  
    scanf("%d", &N);

 
    int initialPrices[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &initialPrices[i]);
    }

 
    scanf("%d", &Q);

 
    for (int q = 1; q <= Q; q++) {
        int A, B;

    
        scanf("%d %d", &A, &B);

        initialPrices[A - 1] = B;

    
        printf("Case #%d:", q);
        for (int i = 0; i < N; i++) {
            printf(" %d", initialPrices[i]);
        }
        printf("\n");
    }

    return 0;
}
