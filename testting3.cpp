#include<stdio.h>
#include<string.h>

struct wadaw{
	char name[];
	
};


void swap(int arr[], int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	temp = arr[idx2];
}

void merge_sort_recursion (int arr[], int left, int mid,int right) {
	
	
	
}

void merge_sort(int a[], int length){
	if(left < right){
		int mid = left + (right-left)/2;
		merge_sort_recursion(a, left, mid);
		merge_sort_recursion(a, mid+1, right);	
		merge_sorted_arrays(a, left, mid, right);
		
	}
}

void merge_sorted_arrays(int a[], int left, int mid, int right){
	int left_length = m-l+1;
	int right_length = r-m;
	
	int temp_left[left_length];
	int temp_right[right_lenght]
	
	int i, j, k;
	
	for(int i = 0; i < left_length; i++){
		
	}
	for(int i = 0; i < right_length; i++){
		
	}
	for(int i = 0; j=0; k = left; k <=r; k++){
		if((i<left_length)||temp_left[i] <= temp_right[j]){
			a[k] = temp_left[i];
			i++;
		}
		else{
			a[k] = temp_right[j];
			j++;
		}
	}
}
	
	
	
}


int main(){
	long long int tc;
	scanf("%lli", &tc);
	
	
	for(int i; )	
	
	
	return 0;
}


