#include <stdio.h>

// Function to calculate F(n)
long long int F(int n, int *count) {
    // Base cases
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2;
    }

    // Check if n is a multiple of 3
    if (n % 3 == 0) {
        (*count)++;  // Increment the count if n is a multiple of 3
    }

    // Check if n is a multiple of 5
    if (n % 5 == 0) {
        return 2 * n;  // If n is a multiple of 5, return 2 times n
    }

    // Recursive case
    return F(n - 1, count) + n + F(n - 2, count) + (n - 2);  // Recursive calculation
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int count = 0;  // Initialize a count variable to zero
        long long int result = F(N, &count);  // Call the F function to calculate result and update the count

        printf("Case #%d: %lld %d\n", i, result, count);  // Print the result and count for this case
    }

    return 0;
}
