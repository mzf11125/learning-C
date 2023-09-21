#include <stdio.h>

int main() {
    long long A, B, C, D;
    long long X, Y, Z;

    for (int i = 0; i < 3; i++) {
        scanf("(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D);
        getchar();
        if (i == 0) {
            X = (A + B) * (C - D);
        } else if (i == 1) {
            Y = (A + B) * (C - D);
        } else {
            Z = (A + B) * (C - D);
        }
    }

    printf("%lld %lld %lld\n", X, Y, Z);

    return 0;
}