#include <stdio.h>


int main(){
	int N, M;
	
	scanf("%d %d", &N, &M);
	getchar();
	
	if (N >= 1 && N <= 1000000 && M >= 1 && M <= 1000000 && N >= M){
		
		int division = N / M;
	
		printf("%d\n", division);
	}
	else {
		printf("Number must be higher than 1 and lower than 1000000! The number to be divided must be greater than the divisor.\n");
	}
}

