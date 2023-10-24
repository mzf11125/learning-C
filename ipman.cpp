#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int N = 0;
        scanf("%d ", &N);
        int biton = 0;
        long long numbers[N+1];
        long long result;
        int count = 0;
        int index = 0;
        for(int j = 0; j < N; j++){
            scanf("%lld", &numbers[j]);
        }
        for(int j = 0; j < N-1; j++){
            for(int k = j+1; k < N; k++){
                index++;
                result=numbers[j]^numbers[k];
                biton = 0;
                for(int l = 0; l < 64; l++){
                    if(result & (1<<l)>0){
                        biton++;
                    }
                    if(biton>=3){
                        break;
                    }
                }
                if(biton>=3){
                    count++;
                }
            }
        }
        printf("Case #%d: %d %d\n", i, count, index);
    }


}
//Satu ppertama kali di petak ke berapa 
//m=2 mati