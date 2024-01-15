#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N + 1][N + 1];
    arr[0][0] = 3;
    arr[1][0] = 3;
    arr[1][1] = 3;

    for (int line = 0; line <= N; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            if (i == 0 || i == line)
                arr[line][i] = 3;
            else
                arr[line][i] = arr[line - 1][i] + arr[line - 1][i - 1];
        }
    }
    // O(N^2)
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", arr[N][i]);
    }
    printf("\n");

    return 0;
}