#include <stdio.h>
#include <math.h>

long long find_smallest_N(long long M) {
    long long low = 0;
    long long high = M;

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;

        if (sum <= M) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        long long M;
        scanf("%lld", &M);

        long long N = find_smallest_N(M);

        printf("Case #%d: %lld\n", i, N);
    }

    return 0;
}