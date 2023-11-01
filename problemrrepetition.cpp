#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t;
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++){
        
        int loop;
        scanf("%d", &loop); getchar();
        
        long long *house = (long long*) malloc(loop * sizeof(long long)); //
        long long min = 2e9;//2 billion = 2 * 10^9
        long long temp = 0;
        
        for(int j = 0; j < loop; j++){
            scanf("%lld", &house[j]);
        }
        
        for(int j = 0; j < loop-1; j++){
            if(house[j] > house[j + 1]){
                temp = house[j] - house[j + 1];
            }
            else if(house[j] < house[j + 1]){
                temp = house[j + 1] - house[j];
            }
             if (min > temp){
                    min = temp;
                }
        }
        printf("Case #%d: %lld\n", i, min);
        
        free(house);
    }
    
    return 0;
}