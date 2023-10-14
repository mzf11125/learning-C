#include <stdio.h>

int rowcheck(int a [9][9]){
	int c[10]={0};
	for(int i = 0;i < 9; i++){
		for(int j = 0;j < 9; j++){
			c[a[i]][j]]++;
		}
		for(int k = 1;k <= 9; k++){
			if(c[k]!=1){
				return 0;
			}
		}
	}
}