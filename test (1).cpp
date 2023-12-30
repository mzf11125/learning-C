#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;

struct data{
	char location[5005];
	char city[5005];
	int price;
	int room;
	int bathroom;
	int carpark;
	char type[5005];
	char furnish[5005];
} searchData[10005];

void merge(struct data arr[], int low, int mid, int high){
	// size
	int leftsize = mid - low + 1;
	int rightsize = high - mid;
	
	// buar arr variable
	struct data left[leftsize];
	struct data right[rightsize];
	
	// isi arr variable
	for(int i = 0; i < leftsize; i++){
		left[i] = arr[i+low];
	}
	for(int i = 0; i < rightsize; i++){
		right[i] = arr[i+mid+1];
	}
	
	// declare
	int dataIdx = low;
	int leftIdx = 0;
	int rightIdx = 0;
	
	// bandingkan
	while(leftIdx < leftsize && rightIdx < rightsize){
		if(strcmp(left[leftIdx].location, right[rightIdx].location) < 0){
			arr[dataIdx] = left[leftIdx];
			leftIdx++;
			dataIdx++;
		} else{
			arr[dataIdx] = right[rightIdx];
			rightIdx++;
			dataIdx++;
			
		}
	}
	
	while(leftIdx < leftsize){
		arr[dataIdx] = left[leftIdx];
		leftIdx++;
		dataIdx++;
	}
	while(rightIdx < rightsize){
		arr[dataIdx] = right[rightIdx];
		rightIdx++;
		dataIdx++;	
	}
}

void mergesort(struct data arr[], int low, int high){
	if(low >= high){
		return;
	}
	
	int mid = (low + high)/2;
	mergesort(arr, low, mid);
	mergesort(arr, mid+1, high);
	
	merge(arr, low, mid, high);
}
int main()
{
	fp = fopen("file.csv", "r");
	if(fp == NULL){
		printf("GABISA ANJIR");
		return 1;
	}
	fscanf(fp, "%[^\n]\n");
	
	int count = 0;
	while(!feof(fp) && count < 10000){
		fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", searchData[count].location, searchData[count].city, &searchData[count].price, &searchData[count].room, 
			&searchData[count].bathroom, &searchData[count].carpark, searchData[count].type, searchData[count].furnish);\
//		printf("Location.55");
		printf("%s %s %d %d %d %d %s %s\n", searchData[count].location, searchData[count].city, searchData[count].price, searchData[count].room, 
        searchData[count].bathroom, searchData[count].carpark, searchData[count].type, searchData[count].furnish);		
		count++;
	}
	
	printf("Number of records read: %d\n", count);
	
	mergesort(searchData, 0, count-1);
	for(int i = 0; i < count; i++)
	{
		printf("%s %s %d %d %d %d %s %s\n", searchData[i].location, searchData[i].city, searchData[i].price, searchData[i].room, searchData[i].bathroom, searchData[i].carpark, searchData[i].type, searchData[i].furnish);
	}
	fclose(fp);
	return 0;
}
