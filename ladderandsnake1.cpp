#include <stdio.h>

int main() {
    int ladders[] = {9, 33, 76};
    int ladder_tops[] = {21, 42, 92};
    int snakes[] = {53, 80, 97};
    int snake_tails[] = {37, 59, 88};

    int N;
    scanf("%d", &N);

    int position = 0; // Lili starts at square 0

    for (int i = 0; i < N; i++) {
        int ki;
        scanf("%d", &ki);

        // Move Lili according to the dice roll
        position += ki;

        // Check if Lili landed on a ladder or a snake
        for (int j = 0; j < 3; j++) {
            if (position == ladders[j]) {
                position = ladder_tops[j];
                break;
            }
            if (position == snakes[j]) {
                position = snake_tails[j];
                break;
            }
        }
    }

    printf("%d\n", position); // Output Lili's final position

    return 0;
}
