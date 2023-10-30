#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        int A, B, C, D, E, F;
        scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

        printf("Case #%d: ", case_num);

        for (int i = 0; i < A; i++) {
            printf("a");
        }
        for (int i = 0; i < B; i++) {
            printf("s");
        }
        for (int i = 0; i < C; i++) {
            printf("h");
        }
        for (int i = 0; i < D; i++) {
            printf("i");
        }
        for (int i = 0; i < E; i++) {
            printf("a");
        }
        for (int i = 0; i < F; i++) {
            printf("p");
        }

        printf("\n");
    }

    return 0;
}
