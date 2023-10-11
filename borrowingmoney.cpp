#include <stdio.h>

int main(){
	int N;
    
	scanf("%d", &N);

	int a[N], results;
	
	
	if(N <= 1000 && N>=1){
	  
	  for (int i = 0; i < N; i++){
       scanf("%d", &a[i]);
       results += a[i];
      }
      
    printf("%d\n", results);
	}


    
    return 0;
}

