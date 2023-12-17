#include<stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
		if (arr[mid]==x && ((arr[mid]>arr[mid-1]) || mid==0))
            return mid + 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    int A[N];
    int Q[M];

   
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

  
    for (int i = 0; i < M; i++) {
        scanf("%d", &Q[i]);
    }

   
    for (int i = 0; i < M; i++) {
        int result = binarySearch(A, 0, N - 1, Q[i]);

        printf("%d\n", result); 
    }

    return 0;
}