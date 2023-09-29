#include <stdio.h>

int main() {
    int num;

    scanf("%d", &num);
	
	if (num <= 1000 && num >= 1){
	
    	if (num % 2 == 0) {
        	printf("EVEN\n", num);
    	} else {
        	printf("ODD\n", num);
    	}
	}

    return 0;
}
