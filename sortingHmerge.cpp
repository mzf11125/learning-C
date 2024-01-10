#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[], int n)
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

void merge(char arr[][205], int left, int middle, int right, int x)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char L[n1][205], R[n2][205];

    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[left + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[middle + 1 + j]);

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            strcpy(arr[k], L[i]);
            i++;
        }
        else
        {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2)
    {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][205], int left, int right, int x)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle, x);
        mergeSort(arr, middle + 1, right, x);

        merge(arr, left, middle, right, x);
    }
}

int main()
{
    int y, x;
    scanf("%d %d", &y, &x);
    char arr[205][205];
    for (int i = 0; i < y; i++)
    {
        scanf("%s", &arr[i]);
        getchar();
        bubbleSort(arr[i], x);
    }
    mergeSort(arr, 0, y - 1, x);
    for (int i = 0; i < y; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}
