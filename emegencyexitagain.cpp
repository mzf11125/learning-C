#include <stdio.h>
#include <string.h>

int main() {
    int Tc;
    scanf("%d", &Tc);
    getchar();

    for (int i = 1; i <= Tc; i++) {

        long long int N, K;
        scanf("%lld %lld", &N, &K);
        getchar();

        char h[N + 5];
        scanf("%s", h);
        getchar();

        if (K >= N) {
            printf("Case #%d: Alive\n", i);
            continue;
        }

        long long int count = 0;
        long long int location1 = -1;
        long long int location2 = -1;

        for (int j = 0; j < N; j++) {
            count++;
            if (count > K) break;
            if (h[j] == '1') {
                location1 = j;
                break;
            }
        }

        if (count > K) {
            printf("Case #%d: Dead\n", i);
            continue;
        }

        count = 0;

        for (int j = N - 1; j >= 0; j--) {
            count++;
            if (count > K) break;
            if (h[j] == '1') {
                location2 = j;
                break;
            }
        }

        if (count > K) {
            printf("Case #%d: Dead\n", i);
            continue;
        }

        if (location2 == location1) {
            printf("Case #%d: Dead\n", i);
            continue;
        }

        printf("Case #%d: Alive\n", i);
        continue;
    }

    return 0;
}
