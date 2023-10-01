#include <stdio.h>

int main(){
	int T;
    
	scanf("%d", &T);

	int a[T], b[T];

    for (int i = 0; i < T; i ++){
        scanf("%d %d", &a[i], &b[i]);
    }
    
    for (int i = 0; i < T; i++) {
    	if (a[i] != b[i]){
    		char results[20];
    	
    		if (a[i] > b[i]){
           	 sprintf(results,"Go-jo");

       	 	}
			else {
           	 sprintf(results,"Bi-pay");
        	}
        	printf("Case #%d: %s\n", i + 1, results);
		}
		
		else{
			printf("Error! Wrong input, out of constraint\n");
			return 1;
		}

    }
    return 0;
}
