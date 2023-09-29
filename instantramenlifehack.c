#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    char results[T][4];

    for (int caseNumber = 0; caseNumber < T; caseNumber++) {
        int K, N, M;
        scanf("%d %d %d", &K, &N, &M);

        if (K <= N + M) {
            sprintf(results[caseNumber], "yes");
        } else {
            sprintf(results[caseNumber], "no");
        }
    }

    for (int caseNumber = 0; caseNumber < T; caseNumber++) {
        printf("Case #%d: %s\n", caseNumber + 1, results[caseNumber]);
    }

    return 0;
}
