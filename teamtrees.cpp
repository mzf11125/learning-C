#include <stdio.h>

void dfs(int i, int j, int n, int m, int adj[100][100], int visited[100][100]) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
        return;
    }

    visited[i][j] = 1;

    // Print the current element
    printf("%d\n", adj[i][j]);

    // Perform DFS in all adjacent elements
    dfs(i + 1, j, n, m, adj, visited);
    dfs(i - 1, j, n, m, adj, visited);
    dfs(i, j + 1, n, m, adj, visited);
    dfs(i, j - 1, n, m, adj, visited);
}

void solve(int case_num, int n, int m, int matrix[100][100]) {
    printf("Case #%d:\n", case_num);

    int adj[100][100];
    int visited[100][100];
    
    // Initialize adjacency matrix and visited matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            adj[i][j] = matrix[i][j];
            visited[i][j] = 0;
        }
    }

    // Perform DFS for each element in the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                dfs(i, j, n, m, adj, visited);
            }
        }
    }
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    for (int case_num = 1; case_num <= t; ++case_num) {
        int n, m; // Rows and columns
        scanf("%d", &n);
        scanf("%d", &m);

        int matrix[100][100];

        // Input matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }

        solve(case_num, n, m, matrix);
    }

    return 0;
}
