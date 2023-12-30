#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int numbers[], int low, int high) {
    int pivotIdx = high;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (numbers[j] < numbers[pivotIdx]) {
            i++;
            swap(&numbers[i], &numbers[j]);
        }
    }

    i++;
    swap(&numbers[i], &numbers[pivotIdx]);

    return i;
}

void quickSort(int numbers[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pi = partition(numbers, low, high);

    quickSort(numbers, low, pi - 1);
    quickSort(numbers, pi + 1, high);
}

int binarySearch(int numbers[], int search, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (numbers[mid] == search) {
            return mid;
        } else if (numbers[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int tc;
    scanf("%d", &tc);

    int numbers[tc];

    for (int i = 0; i < tc; i++) {
        scanf("%d", &numbers[i]);
    }

    quickSort(numbers, 0, tc - 1);

    int length;
    scanf("%d", &length);
    int search[length];

    for (int i = 0; i < length; i++) {
        scanf("%d", &search[i]);
    }

    for (int i = 0; i < length; i++) {
        int index = binarySearch(numbers, search[i], 0, tc - 1);

        if (index != -1) {
            printf("%d\n", index + 1);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}