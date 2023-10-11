#include <stdio.h>

int main(){
	long long N, results;
    results = 0;
	scanf("%lld", &N);

	long long a;
	
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

