//Flood at Bibi's house
#include<stdio.h>

//Global variable = Everything is clean a.k.a value = 0
int count;
//int arrGlobal[100];
//Coordinate S(source), and the initial point
int playerRow, playerColumn;
//Map
char map[105][105];
//1 char takes 1 byte
//1 int takes 4 byte



void floodfill(int row, int column){
	if(map[row][column] == '#' || map[row][column] == '\n'|| map[row][column] == '\0' || row < 0 || column < 0){
		return;
	}
	//Ketemu titik
	else if(map[row][column] == '.'){//If found dot, then count++ to avoid infiniter loop
		count++;
	}
	
	map[row][column] = '#';
	
    floodfill(row + 1, column); // Check down
    floodfill(row - 1, column); // Check top
    floodfill(row, column + 1); // Check Right
    floodfill(row, column - 1); // Check Left

}

int main(){
	int tc = 0;
	scanf("%d", &tc);
	for(int k = 1; k <= tc; k++){
		int row, column;
		scanf("%d %d", &row, &column);
		
		for(int i= 0; i < row; i++){
			for(int j = 0; j < column+1; j++){//Use +1 for \n
				scanf("%c", &map[i][j]);
				if(map[i][j]=='S'){
					playerRow = i;
					playerColumn = j;
				}
			}
		}
		floodfill(playerRow, playerColumn); //Take row and column
		
		printf("Case #%d: %d\n", k, count);
		
		count = 0, playerRow = 0, playerColumn = 0;
		for(int i = 0; i<105; i++){
			for(int j=0; j<105;j++){
				map[i][j]='\0'; //Null terminator
			}
		}
	}
	return 0;
}