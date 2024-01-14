#include <stdio.h>

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld", &n);
        printf("Case #%d: ", i);
        if (n == 1) {
            printf("Lili\n");
        } else if (n % 2 == 0) {
            printf("Lili\n");
        } else {
            printf("Jojo\n");
        }
    }
    return 0;
}
