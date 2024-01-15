#include <stdio.h>

void merge(int arr[], int left, int right)
{
    int middle = (left + right) / 2;
    int sortArray[right - left + 1];
    int count = 0;
    int leftindex = left;
    int rightindex = middle + 1;

    while (leftindex <= middle && rightindex <= right)
    {
        if (arr[leftindex] > arr[rightindex])
        {
            sortArray[count] = arr[rightindex];
            count++, rightindex++;
        }
        else if (arr[leftindex] < arr[rightindex])
        {
            sortArray[count] = arr[leftindex];
            count++, leftindex++;
        }
        else if (arr[leftindex] == arr[rightindex])
        {
            sortArray[count] = arr[leftindex];
            count++, leftindex++;
        }
    }

    while (leftindex <= middle)
    {
        sortArray[count] = arr[leftindex];
        count++, leftindex++;
    }

    while (rightindex <= right)
    {
        sortArray[count] = arr[rightindex];
        count++, rightindex++;
    }

    for (int i = 0; i < count; i++)
    {
        arr[left + i] = sortArray[i];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}