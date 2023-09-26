#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    if (N <= 50 && N >= 0) {
        int middle = N / 2;

        printf("%d\n", middle);
    } else {
        printf("Error: N is out of range.\n");
        return 1;
    }

    return 0;
}
