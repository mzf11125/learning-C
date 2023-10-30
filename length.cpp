#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        long long N;
        scanf("%lld", &N);

        int L = 0;
        while (N > 0) {
            L++;
            N /= 10;
        }

        printf("Case #%d: %d\n", i, L);
    }

    return 0;
}
