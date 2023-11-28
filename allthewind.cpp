#include <stdio.h>

int main() {
    int T, N;

    scanf("%d", &T);

    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &N);

        long long colSums[N];

        for (int i = 0; i < N; ++i) colSums[i] = 0;

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c) {
                long long w;
                scanf("%lld", &w);
                colSums[c] += w;
            }

        printf("Case #%d:", tc);

        for (int i = 0; i < N; ++i)
            printf(" %lld", colSums[i]);

        printf("\n");
    }

    return 0;
}
