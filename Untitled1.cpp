#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A = 0;
    int result = 0; // Initialize the result variable outside the loop

    for (int i = 0; i < N; i++) {
        int B;
        scanf("%d", &B);
        result += B; // Accumulate the sum of B values in 'result'
    }

    printf("%d", result);

    return 0; // Add a return statement at the end of the main function
}
