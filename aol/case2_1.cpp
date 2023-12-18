#include <stdio.h>
#include<string.h>

int case;

void menu(){
	do{
		puts("");
		puts("");
		puts("");
		puts("");
		puts("");
		scanf("%lli", &case);getchar();
		switch(case){
			case 1:
				case1();
				break;
			case 2:
				case2();
				break;
			case 3:
				case3();
				break;
			case 4:
				case4();
				break;		
		}
		
	}while(case == 5);
}



void case_1(){
	
	
	
	
}

void case_2(){
	
	
} 

void case_3(){
	
}

void case_4(){
	
	
}



int main(){
	menu();
		
	
	
	return 0;
}







