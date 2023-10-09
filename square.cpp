#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);

    // Check for constraints
    if (N < 1 || N > 100) {
        printf("Invalid input. N should be between 1 and 100.\n");
        return 1; // Exit with an error code
    }

    // Create the square
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0; // Exit successfully
}
