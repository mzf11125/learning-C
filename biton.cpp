//biton

#include <stdio.h>
#include <stdlib.h>


int main(){
    int t, n, pasangan, biton, bitoff;

    scanf("%d", &t);
    for (int i = 1; i<=t; i++){
        scanf("%d", &n);
        biton = 0;
        bitoff = 0;
        pasangan = 0;
        
        for (int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            if (x == 1){
                biton++;
            } else {
                bitoff++;
            }
        }
        if (biton > bitoff){
            printf("Case #%d: %d\n", i, bitoff);
        } else {
            printf("Case #%d: %d\n", i, biton);
        }
    }


    return 0;
}
