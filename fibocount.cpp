#include <stdio.h>

int fiboCalls[31];

int fibo(int n) {
    
    if (fiboCalls[n] != -1) {
        return fiboCalls[n];
    }

    
    fiboCalls[n] = 1;

   
    if (n > 1) {
        fiboCalls[n] += fibo(n - 1) + fibo(n - 2);
    }

    return fiboCalls[n];
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= 30; i++) {
        fiboCalls[i] = -1; 
    }

    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);

        printf("Case #%d: %d\n", i, fibo(n + 1) - 1);
    }

    return 0;
}
