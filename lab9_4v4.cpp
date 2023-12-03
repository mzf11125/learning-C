#include <stdio.h>
#include <string.h>

char string[1005];
int count = 0;

void fiboString(int num, char a, char b){
	if(num == 0){
        string[count] = a;
        count++;
        return; 
    }
    else if(num == 1){
        string[count] = b;
        count++;
        return;
    }
    
    fiboString(num-1, a, b);
    fiboString(num-2, a, b);
}


int main(){
	
	int testcase;
	scanf("%d", &testcase); getchar();
	
	for(int i = 1; i <= testcase; i++){
		int num;
		char char1, char2;
		scanf("%d %c %c", &num, &char1, &char2); getchar();
		
		fiboString(num, char1, char2);
        string[count] = '\0'; // trailing spaces
        printf("Case #%d: %s\n", i, string);
        count = 0;
	}
	
	return 0;
}