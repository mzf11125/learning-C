#include <stdio.h>
// Time Complexity diukur pake Big O Notation
// O(n) : n = iterasi berapa kali
// O(n) : Worst Case, Average Case, Best Case

// Space Complexity membutuhkan berapa space untuk eksekusi

void print(int a[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	puts("");
}

//Bubble Sort
//void bubble(int a[], int size){
//	for(int i = 0; i < size; i++){
//		int swap = 0;
//		for(int j = 0; j < size-i-1; j++){
//			if(a[j] < a[j+1]){
//				int temp  = a[j];
//				a[j] = a[j+1];
//				a[j+1] = temp;
//				swap= 1;
//			}
//		}
//		if(swap == 0) return;
//	}
//}
//
//void inversebubble(int a[], int size){
//	for(int i = 0; i < size; i++){
//		int swap = 0;
//		for(int j = 0; j < size-i-1; j++){
//			if(a[j] > a[j+1]){
//				int temp  = a[j];
//				a[j] = a[j+1];
//				a[j+1] = temp;
//				swap = 1;
//			}
//		}
//		if(swap == 0) return;
//	}
//}
//
//int main()
//{
//	int a[] = {22, 55, 12, 77, 90};
//	print(a, 5);
//	bubble(a, 5);
//	print(a, 5);
//	inversebubble(a, 5);
//	print(a, 5);
//	
//	return 0;
//}

//Selection Sort
//void select(int a[], int size){
//	for(int i = 0; i < size; i++){
//		int min = i;
//		for(int j = i+1; j < size; j++){
//			if(a[min] < a[j]){
//				min = j;
//			}
//		}
//		int temp = a[i];
//		a[i] = a[min];
//		a[min] = temp;
//	}
//}
//void inverseselect(int a[], int size){
//	for(int i = 0; i < size; i++){
//		int min = i;
//		for(int j = i+1; j < size; j++){
//			if(a[min] > a[j]){
//				min = j;
//			}
//		}
//		int temp = a[i];
//		a[i] = a[min];
//		a[min] = temp;
//	}
//}
//
//int main()
//{
//	int a[] = {22, 55, 12, 77, 90};
//	print(a, 5);
//	select(a, 5);
//	print(a, 5);
//	inverseselect(a, 5);
//	print(a, 5);
//	
//	return 0;
//}

//Insertion Sort
//void insert(int a[], int size){
//	for(int i = 1; i < size; i++){
//		int key = a[i];
//		int j = i-1;
//		while(j >= 0 && a[j] < key){
//			a[j+1] = a[j];
//			j--;
//		}
//		a[j+1] = key;
//	}
//}
//void inverseinsert(int a[], int size){
//	for(int i = 1; i < size; i++){
//		int key = a[i];
//		int j = i-1;
//		while(j >= 0 && a[j] > key){
//			a[j+1] = a[j];
//			j--;
//		}
//		a[j+1] = key;
//	}
//}
//
//int main()
//{
//	int a[] = {22, 55, 12, 77, 90};
//	print(a, 5);
//	insert(a, 5);
//	print(a, 5);
//	inverseinsert(a, 5);
//	print(a, 5);
//	
//	return 0;
//}
