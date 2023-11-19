#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);

        int initial;
        scanf("%d", &initial);

        int max = initial;

        for (int i = 1; i < N; ++i) {
            int Xi;
            scanf("%d", &Xi);

            if (Xi > max && Xi <= M) {
                max = Xi;
            }
        }

        printf("Case #%d: %d\n", t, max);
    }

    return 0;
}
