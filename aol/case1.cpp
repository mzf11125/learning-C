#include <stdio.h> //Import standart input output library
#include <string.h> //Import string library

int main(){
	char arr[105];//Declare string x
	scanf("%[^\n]", arr); // scaf for string x until new line
	for(int i = 0; i < strlen(arr); i++){ //For loop to check the char in the arrays a.k.a the sentence
		if(arr[i]>='A' && arr[i]<='Z'){//if char is greater than or equal to A capital and less than or equal to Z capital then convert it into lowercase
			arr[i]+=32;//+32 in ASCII convert lowercase into 
		}
		else if(arr[i]>='a' && arr[i]<='z'){
			arr[i]-=32;
		}		
	}
	
	for(int i = strlen(arr)-1; i>=0; i--){
		printf("%c", arr[i]);	
	}
	printf("\n");
}