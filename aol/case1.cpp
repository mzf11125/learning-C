#include <stdio.h> //Import standart input output library
#include <string.h> //Import string library

int main(){
	char x[105];//Declare string x
	scanf("%[^\n]", x); // scaf for string x until new line
	for(int i = 0; i < strlen(x); i++){ //For loop to check the char in the arrays a.k.a the sentence
		if(x[i]>='A' && x[i]<='Z'){//if char is greater than or equal to A capital and less than or equal to Z capital then convert it into lowercase
			x[i]+=32;//+32 in ASCII convert lowercase into 
		}
		else if(x[i]>='a' && x[i]<='z'){
			x[i]-=32;
		}		
	}
	
	for(int i = strlen(x)-1; i>=0; i--){
		printf("%c", x[i]);	
	}
	printf("\n");
}