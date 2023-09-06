#include <stdio.h>

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int test = 1; test <= T; test++) {
        int K, N, M;
        scanf("%d %d %d", &K, &N, &M);
        
        if(N+M>= K){
            printf("Case #%d: yes\n",test);
        }
        else {
            printf("Case #%d: no\n",test);
        }
        
    }
    getchar();
    return 0;
}

