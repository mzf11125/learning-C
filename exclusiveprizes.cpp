#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *items = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &items[i]);
    }

    int *count = (int *)calloc(1001, sizeof(int));
    int packets = 0;

    for (int i = 0; i < N; i++) {
        if (count[items[i]] == 0) {
            packets++;
        }
        count[items[i]] = 1;
    }
    
    if (packets % 2 == 0) {
        packets /= 2;
    }


    printf("%d\n", packets);

    free(items);
    free(count);

    return 0;
}
