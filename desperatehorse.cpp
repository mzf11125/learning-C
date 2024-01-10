#include <stdio.h>

#define MAX_N 8

int n, m;
char arr[MAX_N][MAX_N];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int get_row(char c)
{
    return c - 'A';
}

int get_col(char c)
{
    return c - '1';
}

int dfs(int i, int j, int dest_row, int dest_col, int steps)
{
    if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 'o' || steps < 0)
    {
        return -1;
    }
    if (i == dest_row && j == dest_col)
    {
        return steps;
    }
    arr[i][j] = 'o';
    int min_steps = -1;
    for (int k = 0; k < 8; ++k)
    {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        int res = dfs(new_i, new_j, dest_row, dest_col, steps - 1);
        if (res != -1 && (min_steps == -1 || res < min_steps))
        {
            min_steps = res;
        }
    }
    arr[i][j] = '.';
    return min_steps;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int case_num = 1; case_num <= t; ++case_num)
    {
        scanf("%d", &n);
        char c1, c2;
        int x1, x2, y1, y2;
        scanf(" %c%d %c%d", &c1, &y1, &c2, &y2);
        y1--;
        y2--;
        x1 = get_row(c1);
        x2 = get_row(c2);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                arr[i][j] = '.';
            }
        }
        printf("Case #%d: ", case_num);
        int min_steps = dfs(x1, y1, x2, y2, n * n);
        if (min_steps != -1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
