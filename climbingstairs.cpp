#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int current_steps = 0;
    int total_steps = 0;

    for (int i = 0; i < N; i++) {
        int steps;
        scanf("%d", &steps);
        
        if (steps == 1) {
            if (current_steps > 0) {
                printf("%d ", current_steps);
            }
            current_steps = 1;
        } else {
            current_steps++;
        }
        total_steps++;
    }

    printf("%d\n", current_steps);

    return 0;
}
