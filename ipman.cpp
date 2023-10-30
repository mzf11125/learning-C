#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N = 0;
        scanf("%d", &N);  // Read N for each test case
        long long numbers[N + 1];
        long long result;
        int count = 0;
        int index = 0;

        for (int j = 0; j < N; j++) {
            scanf("%lld", &numbers[j]);
        }

        for (int j = 0; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                index++;
                result = numbers[j] ^ numbers[k];
                int biton = 0;
                for (int l = 0; l < 64; l++) {
                    if (result & (1LL << l) > 0) {  // Use 1LL for 64-bit shift
                        biton++;
                    }
                    if (biton >= 3) {
                        break;
                    }
                }
                if (biton >= 3) {
                    count++;
                }
            }
        }

        if (count > 0) {
            printf("Case #%d: YES\n", i + 1);
        } else {
            printf("Case #%d: NO\n", i + 1);
        }
    }

    return 0;
}
