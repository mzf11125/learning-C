#include <stdio.h>

int main()
{
	long long T;
	
	scanf("%lld", &T); 
	for(int i = 1; i <= T; i++){
		long long N;
		scanf("%lld", &N); 
		
		long long hasil = 1;
		for(int j = 0; j < N; j++){
			long long A;
			scanf("%lld", &A); 
			
			long long fact = 1;
			for(int k = 1; k <= A; k++){
				fact = (fact * k) % 1000000007;
			}
			hasil = (hasil * fact) % 1000000007;
		}
		printf("Case #%lld: %lld\n", i, hasil);
	}
	
	
	
	
	return 0;
}
