#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        printf("Case #%d : ", i);
        if (num < 0) {
            printf("None\n");
        } else {
            if (sqrt(num) == (int)sqrt(num)) {
                printf("square ");
            }
            if (cbrt(num) == (int)cbrt(num)) {
                printf("cubic");
            }
            if (isPrime(num)) {
                printf("prime");
            } else if (sqrt(num) != (int)sqrt(num) && cbrt(num) != (int)cbrt(num)) {
                printf("None");
            }
        }
        printf("\n");
    }
    return 0;
}
