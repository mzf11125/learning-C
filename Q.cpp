#include <stdio.h>

int board[8][8] = {0};

int moveX[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int moveY[8] = {1, -1, -2, -2, 1, -1, 2, 2};

int abs(int i){
    if(i < 0){
        i *= -1;
    }
    return 1;
}
int result = 20;
void checkMove(int y1, int x1, int y2, int x2, int y3, int x3, int totalMove){
    if(totalMove > result) {
    	return;	
	}
    if(y3 < 0 || y3 > 7 || x3 < 0 || x3 > 7){
        return;
    }
    if(y3 == y2 && x3 == x2){
        if(totalMove <  result)
        {
            result = totalMove;
        }
        return;
    }  
    if(abs(y1 - y2) < abs(y3 - y2) && abs(x1 - x2) < abs(x3 - x2)){
         return;
    }
    for(int i = 0; i < 8; i++){
        checkMove(y3, x3, y2, x2, y3 + moveY[i], x3 + moveX[i],totalMove + 1);
    }
} 

int main(){
    long long int tc;
    scanf("%lli", &tc);getchar();

    for(int i = 0; i < tc; i++){
        int y1, y2;
        char x1, x2;
        scanf("%c%d %c%d", &x1, &y1, &x2, &y2);getchar();
        x1 -= 'A';
        x2 -= 'A';
        y1 -= 1;
        y2 -= 1;
        result = 20;
        checkMove(y1, x1, y2, x2, y1, x1, 0);
        printf("Case #%d: %d\n", i+1, result);
    }

    return 0;
}
