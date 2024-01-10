#include <stdio.h>

void merge_sort(char arr[205][205], int l, int r, int c)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid, c);
    merge_sort(arr, mid + 1, r, c);
    char temp[205][205];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i][c] >= arr[j][c])
        {
            for (int x = 0; x < c; x++)
            {
                temp[k][x] = arr[i][x];
            }
            i++;
        }
        else
        {
            for (int x = 0; x < c; x++)
            {
                temp[k][x] = arr[j][x];
            }
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        for (int x = 0; x < c; x++)
        {
            temp[k][x] = arr[i][x];
        }
        i++;
        k++;
    }
    while (j <= r)
    {
        for (int x = 0; x < c; x++)
        {
            temp[k][x] = arr[j][x];
        }
        j++;
        k++;
    }
    for (int x = l; x <= r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            arr[x][y] = temp[x - l][y];
        }
    }
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    char arr[205][205];
    for (int i = 0; i < r; i++)
    {
        scanf("%s", &arr[i]);
        getchar();
        merge_sort(arr, 0, c - 1, i);
    }
    for (int i = 0; i < r / 2; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char temp = arr[i][j];
            arr[i][j] = arr[r - i - 1][j];
            arr[r - i - 1][j] = temp;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c / 2; j++)
        {
            char temp = arr[i][j];
            arr[i][j] = arr[i][c - j - 1];
            arr[i][c - j - 1] = temp;
        }
    }
    for (int i = 0; i < r; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}