#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d", &N);

    int views[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &views[i]);
    }

    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        int A, B;
        scanf("%d %d", &A, &B);

        int totalViews = 0;
        for (int i = A - 1; i <= B - 1; i++) {
            totalViews += views[i];
        }

        printf("Case #%d: %d\n", q + 1, totalViews);
    }

    return 0;
}