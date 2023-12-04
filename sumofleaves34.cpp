#include <stdio.h>

// Function to calculate the sum of leaves in each branch using DFS
void sumOfLeaves(int arr[], int n, int index, int currentSum) {
    // Check if the current node is valid
    if (index < n) {
        // Update the current sum
        currentSum += arr[index];

        // Check if the current node is a leaf
        if (2 * index + 1 >= n && 2 * index + 2 >= n) {
            // Print the sum for the current branch
            printf("%d\n", currentSum);
        } else {
            // Recursively explore the left and right subtrees
            sumOfLeaves(arr, n, 2 * index + 1, currentSum);
            sumOfLeaves(arr, n, 2 * index + 2, currentSum);
        }
    }
}

int main() {
    int t; // Number of test cases
//    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int n; 
//        printf("Enter the number of elements in test case %d: ", i + 1);
        scanf("%d", &n);

        int arr[n]; // Array to store the elements
//        printf("Enter the elements for test case %d:\n", i + 1);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }

        // Calculate and print the sum of leaves in each branch using DFS
        printf("Case #%d:\n", i + 1);
        sumOfLeaves(arr, n, 0, 0);
    }

    return 0;
}
