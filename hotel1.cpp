#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int* roomNumbers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &roomNumbers[i]);
    }

    qsort(roomNumbers, N, sizeof(int), compare);

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
