#include <stdio.h>

int main(){
	
	int row, columns;
	scanf("%d %d", &row, &columns);
	
	int array[101][101];
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= columns; j++){
			scanf("%d", &array[i][j]);
		}
		getchar();
	}
	
	int n;
	scanf("%d", &n); getchar();
	
	for(int i = 1; i <= n; i++){
		int changeRow, changeColumns, changeValue;
		scanf("%d %d %d", &changeRow, &changeColumns, &changeValue); getchar();
		
		array[changeRow][changeColumns] = changeValue;		
	}
	
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= columns; j++){
			if(j == columns){
				printf("%d", array[i][j]);
			}
			else{
				printf("%d ", array[i][j]);
			}
		}
		puts("");
	}
	
	
//	for(int i = 1; i <= row; i++){
//		for(int j = 1; j <= columns; j++){
//			printf("%d", array[i][j]);
//		}
//		puts("");
//	}
	
	return 0;
}
