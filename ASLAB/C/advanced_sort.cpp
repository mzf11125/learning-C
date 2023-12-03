//Advanced sorting
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

//Quick sort
//Time complexity O(n*log(n))
void quickSort(int arr[], int low, int high) {
	if(low >= high)return;//Stop/Exit the function
	int partitionIdx = partition(arr, low, high);//Get the partition index
	quickSort(arr, low, partitionIdx - 1);//Left recursion(array, low is the sam, high is the before the array before partition index) 
	quickSort(arr, partitionIdx + 1, high);//Right recursion(array, low is the array after partition index, high is the same) 
}

//merge sort

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
	quickSort(arr, 0, size - 1);
	printArray(arr, size);
}