#include <stdio.h>


int tillOne(int n){
	if (n==1){
		return 1;
	}	
	else if(n % 2 == 0){
		return tillOne(n/2);
	}
	else if(n % 2 != 0){
		return tillOne(n-1) + tillOne(n+1);
	}
}



int main(){
	int N, Tc;
	
	
	scanf("%d", &Tc);
	for(int i = 0; i < Tc; i++){
		scanf("%d", &N);
		printf("Case #%d: %d\n", i+1, tillOne(N));	
	}
	
	
	
	
	
	
}
	
	
	