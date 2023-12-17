#include <stdio.h>

// Function to check if knights can meet in N steps
int canMeet(int x1, int y1, int x2, int y2, int N) {
    // Base case: If N becomes 0, check if the knights are at the same position
    if (N == 0) {
        return (x1 == x2 && y1 == y2);
    }

    // Recursive cases: Try all possible moves for the black and white knights
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int i = 0; i < 8; ++i) {
        int new_x1 = x1 + moves[i][0];
        int new_y1 = y1 + moves[i][1];

        // Check if the new position for the black knight is valid
        if (new_x1 >= 1 && new_x1 <= 8 && new_y1 >= 1 && new_y1 <= 8) {
            // Recursively check if the white knight can meet in the remaining steps
            if (canMeet(new_x1, new_y1, x2, y2, N - 1)) {
                return 1; // Knights can meet
            }
        }
    }

    return 0; // Knights cannot meet
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N;
        char black[3], white[3];
        scanf("%d %s %s", &N, black, white);

        // Convert chessboard coordinates to integer coordinates
        int x1 = black[0] - 'A' + 1;
        int y1 = black[1] - '0';
        int x2 = white[0] - 'A' + 1;
        int y2 = white[1] - '0';

        // Check if knights can meet in N steps
        int result = canMeet(x1, y1, x2, y2, N);

        // Output the result
        printf("Case #%d: %s\n", caseNum, (result ? "YES" : "NO"));
    }

    return 0;
}
