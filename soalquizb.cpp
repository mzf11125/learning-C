#include <stdio.h>

int main() {
    int D, N;

    scanf("%d %d", &D, &N);

    int total = N;
    for (int i = 1; i <= D; i++) {
        total += i * i;
    }

    printf("%d", total);

    return 0;
}
