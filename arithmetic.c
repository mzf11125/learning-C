#include <stdio.h>

int main()
{
    int N, step, M;
    scanf("%d %d", &N, &M);
    
    if (step != 0) {
        for (int i = N; i <= M + 1; i++) {
            printf("%d\n", i);
        }
    }
    else {
        printf("ERRRORORORROROROROROROROROROROROORO!!!!!!!! YOU'VE BEEN HACKED!!!!\n");
    }
    
    return 0;
}