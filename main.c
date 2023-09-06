#include <stdio.h>

int main()
{
    int N,M;
    
    scanf("%d %d", &N, &M);
    
    if(N<=100 && M<=10){
    for (int i=N; i<=N+M-1; i++){
     printf("%d\n", i);   
    }
    }

    return 0;
}

