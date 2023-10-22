#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        
        int A[N], B[N], result[N];
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }
        
        printf("Case #%d:", t);
        for (int i = 0; i < N; i++) {
            result[i] = A[i] - B[i];
            if (result[i] < 0) {
                printf(" %d", result[i]);
            } else {
                printf(" %d", result[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
