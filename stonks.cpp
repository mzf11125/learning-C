#include <stdio.h>

int main(){
	long long N;
    
	scanf("%lld", &N);

	long long a, results;
	
	  
	for (int i = 0; i < N; i++){
       scanf("%lld", &a);
       if(a<0){
            continue;
        }else{
            results += a;
        }
      }
    printf("%lld\n", results);


    
    return 0;
}

