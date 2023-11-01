#include <stdio.h>

int main() {
    int T; // Number of subarrays
    int N; // Number of elements in each subarray

    scanf("%d", &T);
    scanf("%d", &N);

    int subarrays[T][N]; // Create a 2D array to store all the subarrays
    int sum[T]; // Create an array to store the sum of each subarray

    // Input the subarrays
    for (int i = 0; i < T; i++) {
        int subarray_total = 0; // Initialize a variable to store the total of the current subarray

        for (int j = 0; j < N; j++) {
            scanf("%d", &subarrays[i][j]);
            subarray_total += subarrays[i][j];
        }

        sum[i] = subarray_total;
    }

    int max = 0;

    // Calculate the maximum total
    for (int i = 0; i < T; i++) {
        if (sum[i] > max) {
            max = sum[i];
        }
    }

    printf("%d", max);

    return 0;
}
