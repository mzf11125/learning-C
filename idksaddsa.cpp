#include <stdio.h>

void merge(long long arr[], long long left, long long mid, long long right)
{
    long long n1 = mid - left + 1;
    long long n2 = right - mid;

    long long L[n1], R[n2];

    for (long long i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long long i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long long arr[], long long left, long long right)
{
    if (left < right)
    {
        long long mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void function(long long t, long long arr[])
{
    // Your existing function code remains unchanged
    long long angka1 = arr[0] / 2;
    long long angka2 = arr[1] - angka1;
    long long angka5 = arr[24] / 2;
    long long angka4 = arr[23] - angka5;
    long long total = 0;
    for (long long i = 0; i < 25; ++i)
    {
        total += arr[i];
    }
    long long angka3 = (total - 10 * (angka1 + angka2 + angka4 + angka5)) / 10;
    printf("Case #%lld: %lld %lld %lld %lld %lld\n", t, angka1, angka2, angka3, angka4, angka5);
}

int main()
{
    long long T;
    scanf("%lld", &T);
    for (long long t = 1; t <= T; ++t)
    {
        long long S[20005];
        for (long long i = 0; i < 25; ++i)
        {
            scanf("%lld", &S[i]);
        }

        // Sort the array using merge sort before calling the function
        mergeSort(S, 0, 25 - 1);

        function(t, S);
    }
    return 0;
}
