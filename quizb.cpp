#include <stdio.h>




int main(){
	long long int D, N;
	
	
	scanf("%lli %lli", &D, N);
	int total = 0;
	
	for (int i = 0; i < D; i++){
		for (int j = 0; j<i; j++){
			total +=i;
		}
	}
	printf("%lli", total);
	
	
	
	
	
	
	
	
	return 0;
}