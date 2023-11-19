#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        int A, B; 
        scanf("%d %d", &A, &B);

        int total = 0;
        int remaining = A;

        while (remaining >= B) {
            int exchanged = remaining / B;
            total += exchanged;
            remaining = exchanged + remaining % B;
        }

        printf("Case #%d: %d\n", i, total + A);
    }

    return 0;
}
