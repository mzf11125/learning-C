#include <stdio.h>

void reverseOrder(int N, int order[]) {
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        scanf("%d", &N);

        int order[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &order[i]);
        }

        printf("Case #%d: ", caseNum);
        reverseOrder(N, order);
    }

    return 0;
}
