#include <stdio.h>


struct data{
	char name[105];
	char 
}listdata[]; 

void mergesort(int arr[], int low, int mid, int right){
	inf leftsize = mid-low+1;
	int rightsize = right - mid;
	
	
	
}





void merge(int arr[], int low, int right){
	if (low >= high)return;
	int mid = low + (high - low);
	merge(arr, low, mid); //Left
	merge(arr, mid + 1, high); // Right
	mergesort(arr, low, mid, high);	
	
	return;
}


int main(){
	long long int tc;
	
	scanf("%lli", &tc);
	
	
	int arr[tc+1];
	
	for(int i = 0; i < tc; i++){
		scanf("%d", &arr[i]);
	}
	
	merge()
	
		
	
	return 0;
}