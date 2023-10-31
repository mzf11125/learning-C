#include <stdio.h>
#include <string.h>

int main(){
    int t, q, start, m, end;
    char codes[1001], temp[1001];
    scanf("%d", &t); getchar();
    for (int i = 1; i < = t; i++){
        scanf("%d", &q); getchar();
        for(int j = 1; j <= q; j++){
            strcpy(temp, codes);
            scanf("%d %d", &start, &end); getchar();
            start--;
            end--;
            for(int k -start, m=end; k <= end; k++, m--){
                codes[k] = temp[m];
            }
        }

        printf("Case #%d: %s\n", i, codes);
    }


    return 0;
}