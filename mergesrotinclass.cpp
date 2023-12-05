//mergesort with Bu Irene

// 0        1       2       3       4
// 38       29      sa      idk     meto

#include<stdio.h>

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
		if (arrLeft[arrLeftIdx] < arrRight[arrRightIdx]) { //Choose whether ascending or ascending
			arr[arrIdx] = arrLeft[arrLeftIdx];
			arrIdx++;
			arrLeftIdx++;
		} else {
			arr[arrIdx] = arrRight[arrRightIdx];
			arrIdx++;
			arrRightIdx++;
		}
	}
	
	//Merge the rest of the values in the array
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
	int mid = (high + low) / 2; //Divide process, find mid
	//----- Left
	mergeSort(arr, low, mid); //Left recursion(array, the first array, and the array next to it)
	//----- Right
	mergeSort(arr, mid + 1, high);//Right recursion(array, the array next to mid, and the highest array)
//	conquer(combine array)
	merge(arr, low, mid, high); //Combine(arraynya, low number, middle number, high number)
}

void printArray(int arr[], int size) {
	for (int i =0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}


int main(){
	int n = 10;
    int arr[n] = {1,2,3,6,2,2,1,6,3,10};
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}