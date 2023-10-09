#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int flips[T]; // Declare an array to store the flips for each case

    for (int case_num = 0; case_num < T; case_num++) { // Change the loop condition to iterate through all cases
        int N, X;
        scanf("%d %d", &N, &X);

        int flips_case; // Declare a variable to store the flips for the current case

        if (X <= N / 2) {
            flips_case = X - 1; // Calculate flips for the current case
        } else {
            flips_case = N - X; // Calculate flips for the current case
        }

        flips[case_num] = flips_case; // Store flips for the current case in the array
    }

    for (int case_num = 0; case_num < T; case_num++) {
        printf("Case #%d: %d\n", case_num + 1, flips[case_num] % 2); // Output 0 if flips is even, 1 if flips is odd
    }

    return 0;
}
