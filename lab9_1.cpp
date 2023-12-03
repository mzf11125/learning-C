#include <stdio.h>


long long faktorial(int n, int mod) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return (n * faktorial(n - 1, mod)) % mod;
    }
}

int main() {
    int t; 
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n; 
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("Invalid input for N\n");
            return 1;
        }

        long long result = 1;
        for (int j = 0; j < n; j++) {
            int x; // Elemen ke-j
            scanf("%d", &x);

            if (x < 1 || x > 100) {
                printf("Invalid input for A\n");
                return 1;
            }

            result = (result * faktorial(x, 1000000007)) % 1000000007;
        }

        printf("Case #%d: %lld\n", i, result);
    }

    return 0;
}
