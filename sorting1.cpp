#include <stdio.h>

void swap(long long* a, long long* b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

int partition(long long arr[], int low, int high) {
    long long pivot = arr[high];
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

void quicksort(long long arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int N;

    scanf("%d", &N);

    long long arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    quicksort(arr, 0, N - 1);

    long long maxDiff = arr[1] - arr[0];
    for (int i = 1; i < N - 1; i++) {
        long long diff = arr[i + 1] - arr[i];
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        long long diff = arr[i + 1] - arr[i];
        if (diff == maxDiff) {
            printf("%lld %lld ", arr[i], arr[i + 1]);
        }
    }

    return 0;
}
