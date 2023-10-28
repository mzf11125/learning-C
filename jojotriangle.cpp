#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);

        if (A + B > C && B + C > A && A + C > B) {
            printf("BISA\n");
        } else {
            printf("TIDAK BISA\n");
        }
    }

    return 0;
}
