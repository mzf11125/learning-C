#include <stdio.h>
#include <string.h>


int main(){
	char string[101];
	char character[101];
		
	scanf("%s", &string);getchar();
	scanf("%s", &character);
	int len = strlen(string);	
	for (int i = 0; i < len; i++){
		if(string[i] != character[0]){
			printf("%c", string[i]);
		}
	}
	printf("\n");
		
	return 0;
}