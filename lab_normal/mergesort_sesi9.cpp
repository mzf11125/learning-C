//Advanced sorting
//Merge sort
#include <stdio.h>

//Swap
void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

//partition
int partition(int arr[], int low, int high) {
	int pivot = arr[high];//Take pivot from the highest index

	int i = low - 1;

	for(int j = low; j < high; j++) {
		if(arr[j] < pivot) {
			i++; //i = i + 1
			swap(arr, i, j);//swap the array
		}
	}
	i++;
	swap(arr, i, high);
	return i;
}

////Quick sort
////Time complexity O(n*log(n))
//void quickSort(int arr[], int low, int high) {
//	if(low >= high)return;//Stop/Exit the function
//	int partitionIdx = partition(arr, low, high);//Get the partition index
//	quickSort(arr, low, partitionIdx - 1);//Left recursion(array, low is the sam, high is the before the array before partition index)
//	quickSort(arr, partitionIdx + 1, high);//Right recursion(array, low is the array after partition index, high is the same)
//}



//merge

void merge(int arr[], int low, int mid, int high) {
	int leftSize = mid - low + 1; // The size of the left array
	int rightSize = high - mid;   // The size of the right array

	// Make the right and left array variables
	int arrLeft[leftSize];  // The left array
	int arrRight[rightSize]; // The right array

	// Fill the left array
	for (int i = 0; i < leftSize; i++) {
		arrLeft[i] = arr[i + low]; // Left array starts from the 'low' index
	}

	// Fill the right array
	for (int i = 0; i < rightSize; i++) {
		arrRight[i] = arr[i + mid + 1]; // Right array starts from 'mid + 1'
	}

	// Declare indices
	int arrIdx = low;
	int arrLeftIdx = 0;
	int arrRightIdx = 0;

	// Merge the left and right arrays
	while (arrLeftIdx < leftSize && arrRightIdx < rightSize) {
		if (arrLeft[arrLeftIdx] < arrRight[arrRightIdx]) {
			arr[arrIdx] = arrLeft[arrLeftIdx];
			arrIdx++;
			arrLeftIdx++;
		} else {
			arr[arrIdx] = arrRight[arrRightIdx];
			arrIdx++;
			arrRightIdx++;
		}
	}

	// Merge remaining elements from the left array
	while (arrLeftIdx < leftSize) {
		arr[arrIdx] = arrLeft[arrLeftIdx];
		arrIdx++;
		arrLeftIdx++;
	}

	// Merge remaining elements from the right array
	while (arrRightIdx < rightSize) {
		arr[arrIdx] = arrRight[arrRightIdx];
		arrIdx++;
		arrRightIdx++;
	}
}

//merge sort

void mergeSort(int arr[], int low, int high) {
	if(low>=high)return;
	int mid = (high + low) / 2; //Divide process
	mergeSort(arr, low, mid); //Left recursion(array, the first array, and the array next to it)
	mergeSort(arr, mid + 1, high);//Right recursion(array, the array next to mid, and the highest array)
//	conquer(combine array)
	merge(arr, low, mid, high);
}



void printArray(int arr[], int size) {
	for (int i =0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}



int main() {
	//sizeof() --> How big the array is in byte
	//sizeofarr = 24
	//sizeof(int)


	int arr[] = {8, 2, 4, 7, 1, 3};

	int size = sizeof(arr) / sizeof(arr[0]);
//	quickSort(arr, 0, size - 1);
	mergeSort(arr, 0, size-1);
	printArray(arr, size);
}