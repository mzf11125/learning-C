#include <stdio.h>

#define MAX_N 10


int dfs(int x1, int y1, int x2, int y2, int N, int visited[8][8]) {
    if (N == 0) {
        return (x1 == x2 && y1 == y2);
    }

    // Possible moves for a knight
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int i = 0; i < 8; ++i) {
        int new_x1 = x1 + moves[i][0];
        int new_y1 = y1 + moves[i][1];

        if (new_x1 >= 1 && new_x1 <= 8 && new_y1 >= 1 && new_y1 <= 8 &&
            !visited[new_x1 - 1][new_y1 - 1]) {
            
            visited[new_x1 - 1][new_y1 - 1] = 1;

            if (dfs(new_x1, new_y1, x2, y2, N - 1, visited)) {
                return 1;
            }

            visited[new_x1 - 1][new_y1 - 1] = 0;
        }
    }

    return 0;
}


int canMeet(int x1, int y1, int x2, int y2, int N) {
    int visited[8][8] = {0};
    visited[x1 - 1][y1 - 1] = 1;
    return dfs(x1, y1, x2, y2, N, visited);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int N;
        char black[3], white[3];
        scanf("%d %s %s", &N, black, white);

 
        int x1 = black[0] - 'A' + 1;
        int y1 = black[1] - '0';
        int x2 = white[0] - 'A' + 1;
        int y2 = white[1] - '0';

   
        int result = canMeet(x1, y1, x2, y2, N);


        printf("Case #%d: %s\n", caseNum, (result ? "YES" : "NO"));
    }

    return 0;
}
