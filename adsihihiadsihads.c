#include <stdio.h>

int main() {
    int T; // Number of subarrays
    int N; // Number of elements in each subarray

    scanf("%d", &T);
    scanf("%d", &N);

    int element[N]; // Use 'N' instead of 't'
    int total[N];   // Use 'N' instead of 'n'
    int sum[101];

    for (int i = 0; i < T; i++) {
        int subarray_total = 0; // Initialize a variable to store the total of the current subarray
        for (int j = 0; j < N; j++) {
            scanf("%d", &element[j]);
            subarray_total += element[j];
        }
        sum[i] = subarray_total;
    }

    int max = 0;
    for (int i = 0; i < T; i++) {
        if (sum[i] > max)
            max = sum[i];
    }

    printf("%d", max);
    return 0;
}
