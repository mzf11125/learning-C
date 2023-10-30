#include <stdio.h>

int main() {
    int T, i;
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        int X, P;
        scanf("%d %d", &X, &P);

        int bit = (X >> P) & 1;

        printf("%d\n", bit);
    }

    return 0;
}
