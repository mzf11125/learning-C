#include <stdio.h>

void bubblesort(long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        int isSwapped = 0; // Check if the variable is swapped
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = 1;
            }
        }
        if (isSwapped == 0)
            return;
    }
}

void printarray(long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lld ", arr[i]);
    }
    puts(" ");
}

int main() {
    int n;

    // Read the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check if n is within the valid range
    if (n >= 2 && n <= 100000) {
        long long array[100000]; // Use long long for array elements
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &array[i]); // Corrected the array index and variable name
        }
        bubblesort(array, n);
        
        printarray(array, n);
    } else {
        printf("Invalid value of n. Please enter a value between 2 and 100000.\n");
    }

    return 0;
}
