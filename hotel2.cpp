#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int* roomNumbers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &roomNumbers[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (roomNumbers[i] > roomNumbers[j]) {
                int temp = roomNumbers[i];
                roomNumbers[i] = roomNumbers[j];
                roomNumbers[j] = temp;
            }
        }
    }

    int maxHappyGuests = 0;
    int currentRoom = roomNumbers[0];
    int guestCount = 1;
    int unhappyGuests = 0;

    for (int i = 1; i < N; i++) {
        if (roomNumbers[i] == currentRoom) {
            guestCount++;
        } else {
            if (guestCount > maxHappyGuests) {
                maxHappyGuests = guestCount;
            }
            if (currentRoom >= 1) {
                unhappyGuests++;
            }
            currentRoom = roomNumbers[i];
            guestCount = 1;
        }
    }

    if (guestCount > maxHappyGuests) {
        maxHappyGuests = guestCount;
    }
    if (currentRoom >= 1) {
        unhappyGuests++;
    }

    printf("%d\n", unhappyGuests);

    free(roomNumbers);
    return 0;
}
