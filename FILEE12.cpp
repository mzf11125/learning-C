#include <stdio.h>

int perimeter(int n, int *x, int i)
{
    if (i == n)
    {
        return 0;
    }
    int p = 2 * (x[i] + 2);
    if (i > 0)
    {
        p -= 2 * (x[i - 1] < x[i] ? x[i - 1] : x[i]);
    }
    return p + perimeter(n, x, i + 1);
}

int area(int n, int *x, int i)
{
    if (i == n)
    {
        return 0;
    }
    int a = 2 * 2 * x[i];
    return a + area(n, x, i + 1);
}

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    int t, n, x[105];
    fscanf(fp, "%d", &t);
    for (int i = 1; i <= t; i++)
    {
        fscanf(fp, "%d", &n);
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &x[j]);
        }
        int p = perimeter(n, x, 0);
        int a = area(n, x, 0);
        printf("Case #%d: %d %d\n", i, p, a);
    }
    fclose(fp);
    return 0;
}
