#include <stdio.h>

char board[8][8]; // Chess board

int flag = 0; // Flag to indicate if knight can reach destination

// Function to perform knight's tour
void knightTour(int i, int j, int count)
{
    // Base cases for recursion
    if (i >= 8 || j >= 8 || i < 0 || j < 0 || board[i][j] == 'o' || count < 0)
    {
        return;
    }

    board[i][j] = 'o'; // Mark current position as visited
    count--;           // Decrement count of remaining moves

    // Recursive calls for all possible knight moves
    knightTour(i + 1, j + 2, count);
    knightTour(i + 1, j - 2, count);
    knightTour(i - 1, j + 2, count);
    knightTour(i - 1, j - 2, count);
    knightTour(i + 2, j - 1, count);
    knightTour(i + 2, j + 1, count);
    knightTour(i - 2, j + 1, count);
    knightTour(i - 2, j - 1, count);
}

// Function to check if knight can reach destination
void knightTour2(int i, int j, int count)
{
    // Base cases for recursion
    if (i > 8 || j > 8 || i < 0 || j < 0 || count < 0)
    {
        return;
    }

    if (board[i][j] == 'o') // If destination is reached
    {
        board[i][j] = 'X'; // Mark destination as visited
        flag = 1;          // Set flag to indicate success
        return;
    }

    board[i][j] = 'o'; // Mark current position as visited
    count--;           // Decrement count of remaining moves

    // Recursive calls for all possible knight moves
    knightTour2(i + 1, j + 2, count);
    knightTour2(i + 1, j - 2, count);
    knightTour2(i - 1, j + 2, count);
    knightTour2(i - 1, j - 2, count);
    knightTour2(i + 2, j - 1, count);
    knightTour2(i + 2, j + 1, count);
    knightTour2(i - 2, j + 1, count);
    knightTour2(i - 2, j - 1, count);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int cases = 1; cases <= tc; cases++)
    {
        int totalMoves;
        scanf("%d", &totalMoves);
        getchar();

        char startX, destX;
        int startY, destY;
        scanf("%c%d %c%d", &startX, &startY, &destX, &destY);
        getchar();

        startY--;              // Convert to 0-based indexing
        destY--;               // Convert to 0-based indexing
        startX = startX - 'A'; // Convert to 0-based indexing
        destX = destX - 'A';   // Convert to 0-based indexing

        // Initialize chess board
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = '.';
            }
        }

        printf("Case #%d: ", cases);

        // Perform knight's tour from starting position
        knightTour(startX, startY, totalMoves);

        // Check if knight can reach destination
        knightTour2(destX, destY, totalMoves);

        if (flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

        flag = 0; // Reset flag for next test case
    }

    return 0;
}
