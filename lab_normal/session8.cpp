#include <stdio.h>
#include <string.h>
//session 8 : Basic Sorting
//Time complexity diukur pakai Big O Notation
//O(n) : n = iteration how many time

//Function thayt prints array
//Loop how much n times where n: length of array

//O(n) = worst case, average case, best case

//Space complexity : need s how many space for the execution


//	Bubble Sort
// Loop 2 index and compare the 2 indexx which one is bigger 
//If the index is bigger, swap places
//Else don't touch

//void bubblesort(int arr[], int size){
//	for(int i = 0; i < size; i++){
//		int isSwapped = 0; //Check if the variable is swapped
//		for(int j = 0; j < size - i-1; j++){
//			//Cek angka yang berbelahanya
//			if (arr[j] > arr[j+1]){
//				//Tukar angkanya
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//				isSwapped = 1;
//			}
//		}
//		if(isSwapped==0) return;
//	}
//}


//	Selection sort
//Look for the smallest number, swap with index curr
//void selectionsort(int arr[], int size){
//	for(int i = 0; i < size; i++){
//		int min = i;
//		for(int j = i + 1; j < size; j++){
//			if(arr[min] > arr[j]){
//				//update min to the newest
//				min = j;
//			}
//		}
//		//swap min with first index that is unsorted
//		int temp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = temp;
//	}
//}


//	Insertion sort
//Take one index and compare it to all the indexes before
//If it is lower, move it until it is bigger
//If it is bigger, keep it

//void insertionsort(int arr[], int size){
//	for (int i = 1; i < size; i++){
//		int key = arr[i];
//		//looping check in section that is sorted
//		int j = i - 1;
//		while(j >= 0 && arr[j] < key){
//			arr[j+1] = arr[j];
//			j--;
//		}
//		//Put key here
//		arr[j+1] = key;
//	}
//}


//Util to print array
void printarray(int arr[], int size){
	for (int i =0; i < size; i++){
		printf("%d ", arr[i]);
	}
	puts(" ");
}


int main(){
	int arr[] = {5,21,2341,232,1,231};	
	printarray(arr, 6);
//	bubblesort(arr, 6);
//	selectionsort(arr, 6);
	insertionsort(arr, 6);
	printarray(arr, 6);
	return 0;
}
