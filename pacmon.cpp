#include <stdio.h>

#define MAX_N 100
#define MAX_M 100

int n, m;
char map[MAX_N][MAX_M + 1];
int visited[MAX_N][MAX_M];

int dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || map[i][j] == '#' || visited[i][j]) {
        return 0;
    }
    visited[i][j] = 1;
    int count = 0;
    if (map[i][j] == '*') {
        count = 1;
    }
    count += dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int case_num = 1; case_num <= t; ++case_num) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", map[i]);
        }
        int total_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 'P') {
                    total_count = dfs(i, j);
                }
            }
        }
        printf("Case #%d: %d\n", case_num, total_count);
    }
    return 0;
}
