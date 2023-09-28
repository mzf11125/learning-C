#include <stdio.h>

int main() {
    long long x, y, k;
    scanf("%lld %lld %lld", &x, &y, &k);

    if (x < 0LL || x > 100LL || y < 0LL || y > 100LL || k < 0LL || k > 100LL) {
        printf("Invalid input. Elevator floor numbers must be between 0 and 100.\n");
        return 1;
    }

    long long time = -1LL;

    if ((x < k && y > k) || (x > k && y < k)) {
        long long time_to_first, time_to_second;

        if (x < k) {
            time_to_first = k - x;
        } else {
            time_to_first = x - k;
        }

        if (y < k) {
            time_to_second = k - y;
        } else {
            time_to_second = y - k;
        }

        if (time_to_first < time_to_second) {
            time = time_to_first;
        } else {
            time = time_to_second;
        }
    }

    printf("%.0lld\n", time);

    return 0;
}
