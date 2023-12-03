#include <stdio.h>

int calculateFactorial(int n, int a) {
    return (n == 1) ? 1 : (1LL * a * calculateFactorial(n - 1, a)) % 1000000007;
}

int main() {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int n;
        scanf("%d", &n);
        int a[n]; // Use dynamic memory allocation for the array
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        printf("Case #%d:\n", i);

        for (int j = 0; j < n; j++) {
            printf("%d\n", calculateFactorial(a[j], a[j + 1]));
        }
    }

    return 0;
}
