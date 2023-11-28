#include <stdio.h>

int main() {
    int T, N;

    scanf("%d", &T);

    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &N);

        int windMap[N][N];
        int colSums[N];

        for (int i = 0; i < N; ++i) {
            colSums[i] = 0;
            for (int j = 0; j < N; ++j) {
                scanf("%d", &windMap[i][j]);
                if (j <= 2) { // Change this condition to sum different positions (e.g., 1 for the first number, 2 for the second, etc.)
                    colSums[i] += windMap[i][j];
                }
            }
        }

        printf("Case #%d:", tc);

        for (int i = 0; i < N; ++i) {
            printf(" %d", colSums[i]);
        }

        printf("\n");
    }

    return 0;
}
