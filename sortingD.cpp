#include <stdio.h>
#include <string.h>

struct video {
    char video_title[1005];
    char artist_name[1005];
    int view;
};

void merge(struct video arr[], int left, int right) {
    // Calculate the middle index
    int mid = (left + right) / 2;

    // Create a temporary array to store the sorted data after merging
    struct video sortedlist[right - left + 1];

    // Initialize variables for the current index in the sorted array, left array, and right array
    int curr = 0;
    int leftindex = left;
    int rightindex = mid + 1;

    // Merge and sort the data
    while (leftindex <= mid && rightindex <= right) {
        if (arr[leftindex].view == arr[rightindex].view) {

            if (strcmp(arr[leftindex].video_title, arr[rightindex].video_title) < 0) {
                sortedlist[curr] = arr[leftindex];
                curr++;
                leftindex++;
            } else {
                sortedlist[curr] = arr[rightindex];
                curr++;
                rightindex++;
            }

        } else if (arr[leftindex].view < arr[rightindex].view) {
            // If the element in the right array is greater, add it to the sorted array
            sortedlist[curr] = arr[rightindex];
            curr++;
            rightindex++;
        } else {
            // If the element in the left array is greater or equal, add it to the sorted array
            sortedlist[curr] = arr[leftindex];
            curr++;
            leftindex++;
        }
    }

    // Add any remaining elements from the left array
    while (leftindex <= mid) {
        sortedlist[curr] = arr[leftindex];
        curr++, leftindex++;
    }

    // Add any remaining elements from the right array
    while (rightindex <= right) {
        sortedlist[curr] = arr[rightindex];
        curr++, rightindex++;
    }

    // Copy the sorted data back to the original array
    for (int i = 0; i < curr; i++) {
        arr[left + i] = sortedlist[i];
    }
}

// Function to perform merge sort on an array of data
void mergeSort(struct video arr[], int left, int right) {
    // Check if there is more than one element in the array
    if (left < right) {
        // Calculate the middle index
        int mid = (left + right) / 2;

        // Recursively divide the array into two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge and sort the divided arrays
        merge(arr, left, right);
    }
}

int main() {
    int size = 0;
    struct video listvideo[1001];
    FILE *file = fopen("testdata.in", "r");
    int i = 0;
    while (fscanf(file, "%[^#]#%[^#]#%d\n", listvideo[i].video_title, listvideo[i].artist_name, &listvideo[i].view) != EOF) {
        i++;
    }
    size = i;
    fclose(file); 
    mergeSort(listvideo, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%s by %s - %d\n", listvideo[i].video_title, listvideo[i].artist_name, listvideo[i].view);
    }

    return 0;
}
