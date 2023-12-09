#include <stdio.h>

long long reverse(long long num) {
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        long long N;
        scanf("%lld", &N);

        // Calculate the reverse of N
        long long revN = reverse(N);

        // Calculate the sum
        long long sum = N + revN;

        // Print the result
        printf("Case #%d: %lld\n", i, sum);
    }

    return 0;
}
