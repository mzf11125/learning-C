#include <stdio.h>

int countCombinations(int N) {
    int count = 0;

    for (int j = 0; j <= N; j++) {
        for (int l = 0; l <= N; l++) {
            int b = N - (j + l);
            if (b >= 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int combinations = countCombinations(N);

    printf("%d\n", combinations);

    return 0;
}
