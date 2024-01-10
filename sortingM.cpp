#include <stdio.h>

void merge(int arr[], int left, int mid, int high)
{

	long long int left_size = mid - left + 1;
	long long int right_size = right - mid;

	right[right_size];
	left[left_size];
}

void merge_sort(int arr[], int left, int right)
{
	int mid = left + (right - left) / 2;
	if (left >= right)
		;
	return;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main()
{

	retrun 0;
}