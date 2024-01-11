#include <stdio.h>

int main() {
    int T, N, i, j; 
	long long sum;
    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        scanf("%d", &N);
        sum = 0;
        for (j = 0; j < N; j++) {
            long long a;
            scanf("%lld", &a);
            sum += a;
        }
        printf("Case #%d: %lld\n", i, sum);
    }
    return 0;
}
