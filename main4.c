#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);
    
    if(N<=1000){
        if(N % 2 ==0) {
        printf("EVEN\n");
        }
        else {
        printf("ODD\n");
        }
    }
    else{
        printf("Error\n");
    }
    getchar();
    return 0;
}

