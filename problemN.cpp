#include <stdio.h>

int main() {
    long long int t;
    scanf("%lld", &t);

    for (long long int i = 0; i < t; i++) {
        long long int a;
        long long int max = -999999999999LL;
        long long int smax = -999999999999LL;
        long long int result = 0;

        scanf("%lld", &a);
        long long int b[a];

        for (long long int j = 0; j < a; j++) {
            scanf("%lld", &b[j]);
            if (b[j] > max) {
                smax = max;
                max = b[j];
            } else if (b[j] > smax && b[j] != max) {
                smax = b[j];
            } else if (smax == max) { // Fixed the comparison operator
                b[j]++;
            }
        }

        if (smax == -999999999999LL) {
            smax = -1;
        }

        result = max + smax;
        printf("Case #%lld: %lld\n", i + 1, result);
    }

    return 0;
}
