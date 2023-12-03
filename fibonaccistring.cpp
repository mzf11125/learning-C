#include <stdio.h>

// Function to generate the Fibonacci sequence for characters
void generateFibonacci(int t, int n, char s0, char s1) {
    char fib[15];  // Assuming the maximum length of the string won't exceed 20
    fib[0] = s0;
    fib[1] = s1;
    fib[2] = '\0'; // Null-terminate the string

    for (int i = 2; i <= n; ++i) {
        fib[n] = fib[n - 1] + fib[n - 2];
        fib[i + 1] = '\0'; // Null-terminate the string at the end of each iteration
    }

    printf("Case #%d: %s\n", t, fib);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int n;
        char s0, s1;
        scanf("%d %c %c", &n, &s0, &s1);
        generateFibonacci(t, n, s0, s1);
    }

    return 0;
}
