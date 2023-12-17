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
bool result = false;
void checkMove(int y1, int x1, int y2, int x2, int y3, int x3, int totalMove){
    if(y3 < 0 || y3 > 7 || x3 < 0 || x3 > 7){
        return;
    }
    if(y3 == y2 && x3 == x2){
        // printf("Dapat %d %d %d %d %d %d %d\n", y1, x1, y2, x2, y3, x3, totalMove);
        result = true;
        return;
    }
    if(totalMove <= 0){
        return;
    }    
     if(abs(y1 - y2) < abs(y3 - y2) && abs(x1 - x2) < abs(x3 - x2)){
         return;
     }
    // printf("Move : %d %d Remaining : %d\n", y3, x3, totalMove);
    for(int i = 0; i < 8; i++){
        if(result == true) break;
        checkMove(y1, x1, y2, x2, y3 + moveY[i], x3 + moveX[i],totalMove - 1);
    }
}

int main(){
    long long int tc;
    scanf("%lli", &tc);getchar();

    for(int i = 0; i < tc; i++){
        long long int totalMove;
        scanf("%lli", &totalMove);getchar();
        int x1, x2;
        char y1, y2;
        scanf("%c%d %c%d", &y1, &x1, &y2, &x2);getchar();
        y1 -= 'A';
        y2 -= 'A';
        x1 -= 1;
        x2 -= 1;

        result = false;
        checkMove(y1, x1, y2, x2, y1, x1, totalMove * 2);
        if(result){
            printf("Case #%d: YES\n", i+1);
        }else{
            printf("Case #%d: NO\n", i+1);
        }
    }

    return 0;
}
