#include <stdio.h>

int main() {
    long long T, N, M, K, i, j, max;
    scanf("%lld", &T);
    for (i = 1; i <= T; i++) {
        scanf("%lld %lld %lld", &N, &M, &K);
        max = K;
        for (j = 0; j < N; j++) {
            long long X;
            scanf("%lld", &X);
            if (X > max && X <= M) {
                max = X;
            }
        }
        printf("Case #%lld: %lld\n", i, max);
    }
    return 0;
}
