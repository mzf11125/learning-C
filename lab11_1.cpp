#include <stdio.h>

long long sqrt_custom(long long x) {
    long long guess = x / 2;
    long long last_guess = 0;
    while (guess * guess != x && guess != last_guess) {
        last_guess = guess;
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

int minN(long long M) {
    long long lower = 1, upper = sqrt_custom(M);
    while (lower <= upper) {
        long long middle = (lower + upper) / 2;
        long long sum = middle * (middle + 1) * (2 * middle + 1) / 6;
        if (sum >= M) {
            upper = middle - 1;
        } else {
            lower = middle + 1;
        }
    }
    return lower;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        long long M;
        scanf("%lld", &M);
        long long answer = minN(M);
        printf("Case #%d: %lld\n", i, answer);
    }
    return 0;
}
