#include <stdio.h>

int main() {
    int T, N, K, A, i, j;
    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        scanf("%d %d", &N, &K);
        int count = 0;
        for (j = 0; j < N; j++) {
            scanf("%d", &A);
            if (A >= K) {
                count++;
            }
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
