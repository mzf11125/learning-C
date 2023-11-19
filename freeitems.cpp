#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int cost[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &cost[i]);
        }

        int total = 0;
        for (int i = 0; i < N; i++) {
            total += cost[i];
        }

        printf("Case #%d: %s\n", t, (total > M) ? "Wash dishes" : "No worries");
    }

    return 0;
}
