#include <stdio.h>
#include <string.h>

// Define a structure to hold data with a character array for the name
struct data {
    char name[20];
};

// Function to merge and sort an array of data
void merge(struct data arr[], int left, int right) {
    // Calculate the middle index
    int mid = (left + right) / 2;

    // Create a temporary array to store the sorted data after merging
    struct data sortedlist[right - left + 1];

    // Initialize variables for the current index in the sorted array, left array, and right array
    int curr = 0;
    int leftindex = left;
    int rightindex = mid + 1;

    // Merge and sort the data
    while (leftindex <= mid && rightindex <= right) {
        if (strcmp(arr[leftindex].name, arr[rightindex].name) > 0) {
            // If the element in the right array is greater, add it to the sorted array
            sortedlist[curr] = arr[rightindex];
            curr++, rightindex++;
        } else {
            // If the element in the left array is greater or equal, add it to the sorted array
            sortedlist[curr] = arr[leftindex];
            curr++, leftindex++;
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
void mergeSort(struct data arr[], int left, int right) {
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





int recursiveBinarySearch(int arr[], int left, int right, int find){
	if(left <= right){
		//Recursion continue
		int mid = left + (right - left)/2;
		if(arr[mid] == find){
			return mid;
		}else if(arr[mid] < find){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			return recursiveBinarySearch(arr, mid + 1, right,find);
		}else{
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			return recursiveBinarySearch(arr, left, mid - 1, find);
		}
	}	
	return -1;
}


int main() {
    // Merge Sort

    // Apply Merge sort to the struct

    // Input Data
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character

    // Declare an array of struct data to hold input
    struct data listdata[n];

    // Input names into the array
    for (int i = 0; i < n; i++) {
        scanf("%s", listdata[i].name);
        getchar(); // Consume the newline character
    }

    // Apply merge sort to the array
    mergeSort(listdata, 0, n - 1);

    // Output the sorted names
    for (int i = 0; i < n; i++) {
        printf("%s\n", listdata[i].name);
    }

    return 0;
}