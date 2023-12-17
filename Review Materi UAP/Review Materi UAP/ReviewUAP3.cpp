#include <stdio.h>
#include <string.h>

//Review Materi UAP
//15 Desember 2023
//Materi: Sorting,Searching dan File

/*
SOAL 3 : Searching index paling kiri dari suatu angka(binary search)
=====================================================
INPUT :
6 1
1, 1, 2, 2, 3, 3
3

OUTPUT : 
4
*/

int binarySearch(int arr[], int low, int high, int target){

//	int mid = (low + high)/2; kurang disarankan karena seandainya angkanya kebesaran, bisa overflow
	int mid = low + (high - low)/2;
		if(arr[mid]== target&&(arr[mid]>arr[mid-1]||mid==0)){
		return mid;
	}
	
	if (low >= high){
		return -1;
	}
	
	if(target>arr[mid]){
		return binarySearch(arr,mid+1,high,target);
	}else{
		return binarySearch(arr,low,mid-1,target);
	}
}
int main(){
	int N,M;
	//N jumlah angka yang ada dalam array
	//M jumlah target ankga yang mau dicari
	scanf("%d %d", &N,&M);
	int arr[N],target[M];
	//arr[N] adalah angka-angka dari array
	//target adalah angka yang mau dicari
	for(int i = 0;i<N;i++){
		
		scanf("%d",&arr[i]);
	}
	for(int i = 0;i<M;i++){
		scanf("%d",&target[i]);
		int position = binarySearch(arr,0,N-1,target[i]);
		if(position !=-1){
			printf("Target Index(%d): %d \n",i+1, position);	
		}else{
			printf("Target Index(%d): tidak ketemu\n",i+1);
		}
	}
	return 0;
}
