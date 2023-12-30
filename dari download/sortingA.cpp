//	A - SORTING

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
	long long n;
	scanf("%lld", &n); getchar();
	
	long long arr[n + 5];
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	getchar();
	
	mergeSort(arr, 0, n - 1);
	
	long long max = 0;
	
	for(int i = 0; i < n - 1; i++)
	{	
		long long selisih = 0;
		selisih = arr[i + 1] - arr[i];
		if(max < selisih)
		{
			max = selisih;
		}
	}
	
	int count = 0;
	for(int i = 0; i < n - 1; i++)
	{
		long long selisih = 0;
		selisih = arr[i + 1] - arr[i];
		
		if(selisih == max)
		{
			if(count == 0)
			{
				printf("%lld %lld", arr[i], arr[i + 1]);
				count++;
			}
			
			else if(count > 0)
			{
				printf(" %lld %lld", arr[i], arr[i + 1]);
			}
			
		}
	}
	
	printf("\n");
	
	return 0;
}