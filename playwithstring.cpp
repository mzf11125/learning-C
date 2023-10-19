#include<stdio.h>
#include <string.h>

int main(){
    int testcase;
	scanf("%d", &testcase); getchar();
	
	for (int i = 0; i < testcase; i++){
		char string[1001]; // \0 buat pembatas, real constratin 10000, tapi tambah 1 buat \0
		scanf("%s", &string);
		getchar();
		
		int len = strlen(string); //This is much better
//		printf("%s\n", string);
//		scanf("%[^\n]");
		int amount;
		scanf("%d", &amount);
		getchar();
		char a[amount], b[amount];
		for (int j = 0; j < amount; j++){
			//Ubah 1 karakter yang user bikin ubah
			scanf("%c %c", &a[j], &b[j]);
			getchar();
//			printf("%c, %c", a, b); 
			
//			for (int k = 0; k < strlen(string); k++){ This is bad because strlen is sa while loop
		}
		for (int j = 0; j < amount; j++){
			for (int k = 0; k < len; k++){
//				char curr = string[k];
				if(string[k] == a[j]){
					string[k] = b[j];
				}
			}
		}
		printf("Case #%d: %s\n", i + 1, string);
	}
	return 0;
	
//	char a[6] = "makan";
//	a[2] = 'd';
//	printf("%s", a);
	
	    
}


//Stdin vs stdout

//Stdin = 2entera b
//stdout


