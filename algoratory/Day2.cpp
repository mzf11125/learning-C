#include<stdio.h>

//Bakal punya 2 fungsi
//1. Divide
//2. Merge & Sort

//Function Merge & Sort
void merge(int arr[], int left, int right){
	int mid = (left+right)/2;
	int sortedarray[right-left+1]; //Ini untuk store final data abis disort & merge
	int curr= 0; //Kasih tau index sortedarray
	int leftindex = left;
	int rightindex = mid+1;
	
	while(leftindex <= mid && rightindex <= right){
		if(arr[leftindex] > arr[rightindex]){
			sortedarray[curr] = arr[rightindex];
			curr++ , rightindex++;
		}else if(arr[leftindex] < arr[rightindex]){
			sortedarray[curr] = arr[leftindex];
			curr++, leftindex++;
		}else if(arr[leftindex] == arr[rightindex]){
			sortedarray[curr] = arr[leftindex];
			curr++, leftindex++;			
		}
	}
	
	while(leftindex <= mid){
		sortedarray[curr] = arr[leftindex];
		curr++, leftindex++;		
	}
	
	while(rightindex <= right){
		sortedarray[curr] = arr[rightindex];
		curr++ , rightindex++;		
	}
	
	for(int i=0;i<curr;i++){
		arr[left+i] = sortedarray[i];
	}
	
	
}

//Function untuk divide
void mergeSort(int arr[],int left, int right){
	//Kapan ngebelahnya berenti? left >= right
	if(left < right){
		int mid =(left+right)/2;
		//Divide Data
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		
		//Merge Data and Sort
		merge(arr,left,right);
	}
}

int main(){
	//Merge Sort
	//Apply Merge sort ke struct	
	//Input Data
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	mergeSort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
