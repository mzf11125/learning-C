#include <stdio.h>

int main(){
	int t;
	longl on
	scanf("%d", &t);getchar(); //loop
	
	for(int i = 1; i <= t; i++){
		scanf("%lld %lld", &n, &k);getchar();
		
		long long a[n];
		for(int j = 0; j < n; j++){
			long long temp = 0;
			scanf("%lld", &temp);getchar();
			a[temp]++;
		}
		
		printf("Case #%d: %lld\n", i+1, a[k]);
	}
	
	return 0;
}