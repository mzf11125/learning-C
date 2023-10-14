#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Initialize an array to store the frequency of each item type
    int max_type = 1000;  // Adjust this value as needed
    int item_counts[max_type] = {0};

    // Read the types of items
    printf("Enter the types of items (e.g., 1 2 3 4 ...): ");
    for (int i = 0; i < n; i++) {
        int item_type;
        scanf("%d", &item_type);
        item_counts[item_type]++;
    }

    // Count the unique types of items
    int unique_types = 0;
    for (int i = 1; i <= max_type; i++) {
        if (item_counts[i] > 0) {
            unique_types++;
        }
    }

    printf("Minimum number of packets to make prizes exclusive: %d\n", unique_types);

    return 0;
}
