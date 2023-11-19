#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);

        int total = 0;
        int empty = 0;

        total += A;
        empty += A;

        while (empty >= B) {
            int exchanged = empty / B;
            total += exchanged;
            empty = exchanged + (empty % B);
        }

        printf("Case #%d: %d\n", i, total);
    }

    return 0;
}
