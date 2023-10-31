#include <stdio.h>
#include <string.h>

int main(){
    char ip[101];
    int t;
    scanf("%d", &t);getchar();

    for (int i = 1; i <= t; i++){
        int n;
        int len = strlen(ip);
        int flag = 0;
        for(int j = 0; j < n; j++){
            scanf("%s", ip);
            if(ip[j] == '.'){
                if(j != 0 && j != len - 1){
                    printf("Case #%d:\n", i);
                }
                else if (j == 0 || j == len - 1){
                    printf("No\n");
                }
                printf("Case #%d:\n", i);
            }
            // if (len > 0 && len < 101){
            //     for (int k = 0; k < len; k++){
            //         if (ip[k] == '.'){
            //             ip[k] = ip[k + 1];
            //         }
            //     }
            // }
        }
    }

    return 0;
}