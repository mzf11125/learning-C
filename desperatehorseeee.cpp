#include <stdio.h>

int count;

int findMoves(char startX, char startY, char targetX, char targetY, int moves)
{

    // Check if the starting position is out of bounds or if the number of moves exceeds 6
    if (startX < 'A' || startX > 'H' || startY < '1' || startY > '8' || moves > 6)
    {
        return 0;
    }

    // Check if the current position is the target position and the number of moves is less than or equal to the current count
    if (startX == targetX && startY == targetY && moves <= count)
    {
        return count = moves;
    }

    // Recursively explore all possible moves
    findMoves(startX + 1, startY + 2, targetX, targetY, moves + 1);
    findMoves(startX + 1, startY - 2, targetX, targetY, moves + 1);
    findMoves(startX - 1, startY + 2, targetX, targetY, moves + 1);
    findMoves(startX - 1, startY - 2, targetX, targetY, moves + 1);
    findMoves(startX + 2, startY + 1, targetX, targetY, moves + 1);
    findMoves(startX + 2, startY - 1, targetX, targetY, moves + 1);
    findMoves(startX - 2, startY + 1, targetX, targetY, moves + 1);
    findMoves(startX - 2, startY - 1, targetX, targetY, moves + 1);

    return count;
}

int main()
{

    int testcase;
    scanf("%d", &testcase);
    getchar();

    for (int i = 0; i < testcase; i++)
    {

        char startX, targetX;
        char startY, targetY;
        scanf("%c%c %c%c", &startX, &startY, &targetX, &targetY);
        getchar();

        count = 6;

        printf("Case #%d: %d\n", i + 1, findMoves(startX, startY, targetX, targetY, 0));
    }

    return 0;
}