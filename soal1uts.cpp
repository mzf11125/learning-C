#include <stdio.h>

int main(){
    int T;
    int total = 0;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int number, width;
        scanf("%d %d", &number, &width);
        int luas = number * width;
        total += luas;
    }

    printf("%d\n", total);

    return 0;
}