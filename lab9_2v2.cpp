#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        quicksort(arr, 0, n - 1);

        int x;
        scanf("%d", &x);

        int index = binarySearch(arr, 0, n - 1, x);

        printf("CASE #%d: ", caseNum);

        if (index != -1) {
        	if (index == n - 1) {
                printf("%d ", arr[index-1]);
            	printf("%d\n", arr[index]);
            } else {
                printf("%d ", arr[index]);
            	printf("%d\n", arr[index + 1]);
            }
        } else {
            printf("-1 -1\n");
        }
    }

    return 0;
}
