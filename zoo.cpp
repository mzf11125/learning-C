#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total += a[i];
    }

    printf("%d\n", total);

    return 0;
}
