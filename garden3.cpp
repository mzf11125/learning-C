#include <stdio.h>

int main() {
    const int MAX_SIZE = 100;
    int X, Y, T;

    // Read garden dimensions
    if (scanf("%d %d", &X, &Y) != 2 || X < 1 || X > 100 || Y < 1 || Y > 100) {
        printf("Invalid input. Dimensions out of bounds.\n");
        return 1;  // Exit with an error code
    }

    // Use fixed-size array for the garden
    int garden[MAX_SIZE][MAX_SIZE];

    // Read initial garden content
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (scanf("%d", &garden[i][j]) != 1 || garden[i][j] < 1 || garden[i][j] > 100) {
                printf("Invalid input. Garden content out of bounds.\n");
                return 1;  // Exit with an error code
            }
        }
    }

    // Read the number of changes
    if (scanf("%d", &T) != 1 || T < 1 || T > 1000) {
        printf("Invalid input. Number of changes out of bounds.\n");
        return 1;  // Exit with an error code
    }

    // Perform changes
    for (int k = 0; k < T; k++) {
        int a, b, c;

        // Read change details
        if (scanf("%d %d %d", &a, &b, &c) != 3 || a < 1 || a > X || b < 1 || b > Y || c < 1 || c > 100) {
            printf("Invalid input. Change details out of bounds.\n");
            return 1;  // Exit with an error code
        }

        // Update the garden
        garden[a - 1][b - 1] = c;

        // Print the updated garden
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                printf("%d ", garden[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
