//Flood at Bibi's house
#include<stdio.h>

int count;

int playerRow, playerColumn;

char map[105][105];


void white(int row, int column){
	if(map[row][column] == '#' || map[row][column] == '\n'|| map[row][column] == '\0' || row < 0 || column < 0){
		return;
	}
	//Ketemu titik
	else if(map[row][column] == '.'){
		count++;
	}
	
	map[row][column] = '#';
	
    floodfill(row + 1, column); 
    floodfill(row - 1, column); 
    floodfill(row, column + 1); 
    floodfill(row, column - 1); 
}

int main(){
	int tc = 0;
	scanf("%d", &tc);
	for(int k = 1; k <= tc; k++){
		int row, column;
		scanf("%d %d", &row, &column);
		
		for(int i= 0; i < row; i++){
			for(int j = 0; j < column+1; j++){
				scanf("%c", &map[i][j]);
				if(map[i][j]=='S'){
					playerRow = i;
					playerColumn = j;
				}
			}
		}
		floodfill(playerRow, playerColumn); 
		
		printf("Case #%d: %d\n", k, count);
		
		count = 0, playerRow = 0, playerColumn = 0;
		for(int i = 0; i<105; i++){
			for(int j=0; j<105;j++){
				map[i][j]='\0'; 
			}
		}
	}
	return 0;
}