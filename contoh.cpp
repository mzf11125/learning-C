#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    itnt t, n , k, petak[10001];

    scanf("%d", &t); getchar();

    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &k); getchar();
        scanf("%d", petak); getchar();

        for int j = 0; j < n; j++){
            if (petak[j] == 1)
            {
                start = j;
                break;
            }
        }
        for (int j = n -1; j < n; ;j++){
            if (petak[j] == '1')
            {
                end = j;
                break;
            }
        }

        int count = 0;
    }

    return 0;
}