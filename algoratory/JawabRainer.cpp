#include<stdio.h>
#include<string.h>

int main(){
	char x[100];
	scanf("%s",x);
	
	for(int i=0;i<strlen(x)-1; i++){
		for(int j = i+1 ; j<strlen(x); j++){
			if(x[i] > x[j]){
				char temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	
	printf("%s",x);
}
