#include <stdio.h>

void getIndex(long long int *arr, int size, long long int value){
	int l = 0;
	int r = size - 2;//Index/right is usually size-1
	if(arr[r+1] <= value){
		printf("%d\n", r+2);
		return;
	}
	while(l <= r){
		int m = l + (r - l) / 2;

		if(arr[m] <= value && value < arr[m + 1]){//Because m is added by 1 so in line 5, right = size - 2
			printf("%d\n", m+1);//Constraint is index, but what position because position start from 0 so added by 1
			return;
		}else if(arr[m] < value){
			l = m + 1;
//			printf("\nl : %d\n", l);
		}else{
			r = m - 1;
//			printf("\nr : %d\n", r);
		}
	}
	
	printf("-1\n");
}

int main(){
	int size;
	scanf("%d", &size);getchar();
	long long int data[size+5];
	long long int index[size+5];
	
	scanf("%lli", &data[0]);
	for(int i = 1; i < size; i++){
		long long int temp;
		scanf("%lli", &temp);
		data[i] = temp + data[i-1];

	}
	
//	puts("");
//	for(int i = 0; i < size; i++){
//		printf("%lli ",  data[i]);
//	}
//	puts("");
	
	//mergeSort(data);
	
	
	
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; i++){
		long long int num;
		scanf("%lli", &num);getchar();
		printf("Case #%d: ", i+1);
		getIndex(data, size, num);
	}
	
	return 0;
}