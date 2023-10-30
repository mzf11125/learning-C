#include <stdio.h>
#include <string.h>

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++) {
        long long int N, K;
        scanf("%lld %lld", &N, &K);
        getchar();  // Consume the newline character

        char s[N + 5];
        scanf("%s", s);
        getchar();  

        long long int count = 0;
        long long int location1 = -1;
        long long int location2 = -1;

        for (long long int j = 0; j < N; j++) {
            count++;
            if (count > K) break;
            if (s[j] == '1') {
                location1 = j;
                break;
            }
        }

        if (count > K) {
            printf("Case #%d: Dead\n", i);
            continue;
        }

        count = 0;

        for (long long int j = N - 1; j >= 0; j--) {
            count++;
            if (count > K) break;
            if (s[j] == '1') {
                location2 = j;
                break;
            }
        }

        if (count > K || location2 == location1) {
            printf("Case #%d: Dead\n", i);
        } else {
            printf("Case #%d: Alive\n", i);
        }
    }

    return 0;
}
