#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, A, B, C, D;
        scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

        int toysThrownAway = 0;
        for (int i = 1; i <= N; i++) {
            if (i % A == 0 || i % B == 0 || i % C == 0 || i % D == 0) {
                toysThrownAway++;
            }
        }

        printf("Case #%d: %d\n", t, toysThrownAway);
    }

    return 0;
}