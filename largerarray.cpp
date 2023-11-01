#include <stdio.h> // This line includes a library for input and output functions.

int main() {
    int T; // This declares an integer variable 'T' to store the number of subarrays.
    int N; // This declares an integer variable 'N' to store the number of elements in each subarray.

    scanf("%d", &T); // This line reads an integer value from the user and stores it in 'T'.
    scanf("%d", &N); // This line reads another integer value from the user and stores it in 'N'.

    int element[N]; // This creates an array called 'element' to store 'N' integers.
    int total[N];   // This creates another array called 'total' with the same size as 'element'.
    int sum[101];   // This creates an array called 'sum' with 101 elements.

    // Now, we enter a loop that runs 'T' times, where 'T' is the number of subarrays.
    for (int i = 0; i < T; i++) {
        int subarray_total = 0; // This initializes a variable to store the total of the current subarray.

        // Within this loop, we enter another loop that runs 'N' times, where 'N' is the number of elements in each subarray.
        for (int j = 0; j < N; j++) {
            scanf("%d", &element[j]); // This reads an integer from the user and stores it in the 'element' array.
            subarray_total += element[j]; // This adds the integer to the 'subarray_total'.
        }

        sum[i] = subarray_total; // This stores the 'subarray_total' in the 'sum' array.

    }

    int max = 0; // This initializes a variable 'max' to store the maximum subarray total.

    // Now, we enter another loop that goes through the 'sum' array to find the maximum total.
    for (int i = 0; i < T; i++) {
        if (sum[i] > max)
            max = sum[i]; // If the current total is greater than the current maximum, update 'max' with the new maximum.
    }

    printf("%d", max); // Finally, this line prints the maximum subarray total.

    return 0; // This indicates that the program has finished running without any issues.
}
