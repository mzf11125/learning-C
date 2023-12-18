#include<stdio.h>
#include<string.h>

struct data{
	char name[20];
	int mmr;
};
//Function Merge & Sort
void merge(struct data arr[], int left, int right){
	int mid = (left+right)/2;
	struct data sortedlist[right-left+1]; //Ini untuk store final data abis disort & merge
	int curr= 0; //Kasih tau index sortedarray
	int leftindex = left;
	int rightindex = mid+1;
	
	while(leftindex <= mid && rightindex <= right){
		if(arr[leftindex].mmr > arr[rightindex].mmr){
			sortedlist[curr] = arr[leftindex];
			curr++, leftindex++;
		}else if(arr[leftindex].mmr < arr[rightindex].mmr){
			sortedlist[curr] = arr[rightindex];
			curr++, rightindex++;			
		}else if(arr[leftindex].mmr == arr[rightindex].mmr){
			if(strcmp(arr[leftindex].name,arr[rightindex].name) > 0){
				sortedlist[curr] = arr[rightindex];
				curr++, rightindex++;
			}else{
				sortedlist[curr] = arr[leftindex];
				curr++,leftindex++;
			}
		}
	}
	
	while(leftindex <= mid){
		sortedlist[curr] = arr[leftindex];
		curr++, leftindex++;		
	}
	
	while(rightindex <= right){
		sortedlist[curr] = arr[rightindex];
		curr++ , rightindex++;		
	}
	
	for(int i=0;i<curr;i++){
		arr[left+i] = sortedlist[i];
	}
	
	
}

//Function untuk divide
void mergeSort(struct data arr[],int left, int right){
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
	struct data listdata[n];
	
	for(int i=0;i<n;i++){
		scanf("%s %d\n",&listdata[i].name, &listdata[i].mmr);
	}
	
	mergeSort(listdata,0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%s %d\n",listdata[i].name, listdata[i].mmr);
	}
	
	return 0;
}
