#include <stdio.h>

void merge(long long arr[], long long left, long long middle, long long right)
{
	long long leftAmount = middle - left + 1;
	long long rightAmount = right - middle;

	long long leftArray[leftAmount];
	long long rightArray[rightAmount];

	for(int i = 0; i < leftAmount; i++)
	{
		leftArray[i] = arr[left + i];
	}

	for(int i = 0; i < rightAmount; i++)
	{
		rightArray[i] = arr[middle + 1 + i];
	}

	long long leftIndex = 0;
	long long rightIndex = 0;
	long long mainIndex = left;

	while(leftIndex < leftAmount && rightIndex < rightAmount)
	{
		if(leftArray[leftIndex] < rightArray[rightIndex])
		{
			arr[mainIndex] = leftArray[leftIndex];
			leftIndex += 1;
		}

		else
		{
			arr[mainIndex] = rightArray[rightIndex];
			rightIndex += 1;
		}

		mainIndex += 1;
	}

	while(leftIndex < leftAmount)
	{
		arr[mainIndex] = leftArray[leftIndex];
		leftIndex += 1;
		mainIndex += 1;
	}

	while(rightIndex < rightAmount)
	{
		arr[mainIndex] = rightArray[rightIndex];
		rightIndex += 1;
		mainIndex += 1;
	}
}

void mergeSort(long long arr[], long long left, long long right)
{
	if(left < right)
	{
		long long middle = left + (right - left) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int c = 0; c < tc; c++){
        int n;
        scanf("%d", &n);

        int arr[501];
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        mergeSort(arr, 0, n-1);

//        for(int i = 0; i < n; i++)
//        {
//            printf("%d ", arr[i]);
//        }

        int matrix[2][501];
        int k = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                matrix[i][j] = arr[k];
//                printf("%d ", matrix[i][j]);
                k++;
            }
        }
        
        int max = 0;
        int selisih = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < (n/2) - 1; j++)
            {
                selisih = matrix[i][j+1] - matrix[i][j];
                if(max < selisih)
                {
                    max = selisih;
                }
            }
        }
        
        printf("Case #%d: %d\n", c+1, max);
    }
    return 0;
}