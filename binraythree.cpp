#include <stdio.h>

int countOnBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int count3OnBits = 0;
        int countNot3OnBits = 0;

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int xorResult = arr[i] ^ arr[j];
                int onBits = countOnBits(xorResult);
                if (onBits >= 3) {
                    count3OnBits++;
                } else {
                    countNot3OnBits++;
                }
            }
        }

        printf("Case #%d: %d %d\n", t, count3OnBits, countNot3OnBits);
    }

    return 0;
}
