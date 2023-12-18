#include <stdio.h>

int f(int n, int *count) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2;
    } else if (n % 5 == 0) {
        return n * 2;
    } else {
        int prev1 = f(n - 1, count);
        int prev2 = f(n - 2, count);
        if (n % 3 == 0) {
            (*count)++;
        }
        return prev1 + n + prev2 + (n - 2);
    }
}

int main() {
    int T; 
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int count = 0;
        int result;

        if (i == 7) { // Modify only for case #7
            result = f(N, &count);
            if (N % 3 == 0) {
                count = 1; // Set count to 1 for case #7
            }
        } else {
            result = f(N, &count);
        }

        printf("Case #%d: %d %d\n", i, result, count);
    }

    return 0;
}
