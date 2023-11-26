#include <stdio.h>

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
        int num[200][200] = {0};
        for(int i = 0; i < q; i++){
            int x, y, a;
            scanf("%d %d %d", &x, &y, &a);
            num[x][y] = a;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d", num[i][j]);
                if(j < m - 1){
                    printf(" ");
                }
            }
            printf("\n");
        }
}