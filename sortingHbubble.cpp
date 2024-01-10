
#include <stdio.h>
#include <string.h>

void sortChar(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortArray(char arr[][205], int rows)
{
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) < 0)
            {
                char temp[205];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main()
{
    int y, x;
    scanf("%d %d", &y, &x);
    char arr[2005][205];
    for (int i = 0; i < y; i++)
    {
        scanf("%s", &arr[i]);
        getchar();
        sortChar(arr[i], x);
    }
    sortArray(arr, y);
    for (int i = 0; i < y; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}