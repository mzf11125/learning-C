#include <stdio.h>

int main(){
	int num1, num2;
	FILE *fp = fopen("testdata.in", "r");
//	FILE *fp = fopen("number.txt", "r");
	
	fscanf(fp, "%d %d", &num1, &num2);
	printf("%d\n", num1+num2);
	fclose(fp);
	return 0;
}