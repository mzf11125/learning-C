#include <stdio.h>

int main()
{
    int N, step, M;
    scanf("%d %d", &N, &M);
    scanf("%d", &step); // 

        for (int i = N; i <= M + 1; i += step) { // Change the loop increment to 'step'
            printf("%d\n", i);
        }

    return 0;
}
