#include <stdio.h>


void fraktal_B(int x) {
 int i;
 if (x <= 0) return;
 else {
 fraktal_B(x - 1);
 for (i = 1; i <= x; i++) printf("*");
 printf("\n");
 fraktal_B(x - 2);
 }
}


int main(){
	
	scanf("");
	
	
	
	
	
	
	return 0;
}