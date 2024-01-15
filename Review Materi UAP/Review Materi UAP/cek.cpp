#include <stdio.h>
#include <string.h>

void mergesort(char *s, )
{
}
void sort(char *s, int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int r1 = right - mid;
    char L[l1 + 1];
    char R[r1 + 1];
    for (int k = 0; k < l1; k++)
    {
        L[k] = s[left + k];
    }
    for (int k = 0k < r1; k++)
    {
        R[k] = s[mid + 1 + k];
    }
    int i, j, k;
    i = j = 0, k = left;
    while (i < l1 && j < r1)
    {
        if ()
        {
            s[k] = L[i];
            i++;
        }
        else
        {
            s[k] = R[j];
            j++;
        }
        else if ()
        {
        }
    }
}

int main(void)
{
    // int n;
    // scanf("%d", &n);
    // int a[n];
    // int i;
    // for (i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }
    // int max = a[0];
    // int min = a[0];
    // int sum = 0;
    // for (i = 0; i < n; i++) {
    //     if (a[i] > max) {
    //         max = a[i];
    //     }
    //     if (a[i] < min) {
    //         min = a[i];
    //     }
    //     sum += a[i];
    // }
    // printf("%d\n", max);
    // printf("%d\n", min);
    // printf("%d\n", sum);
    // return 0;

    char s[1001];
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int case = 1; case <= tc; case ++)
    {
        char s[1005];
        scanf("%s", &s);
        char u[1005];
        scanf("%s", &s);
        char ans[1005] = "";
        int k = 0;
        ;
        scanf("%s", &s);
        for (int i = 0; i < strlen(u); i++)
        {
            for (int j = 0; j < strlen(s); j++)
            {
                if (u[i] == s[j])
                {
                }
            }
        }
        return 0;
    }