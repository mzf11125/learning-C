#include <stdio.h>
#include <string.h>

void sort(char s[], int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int r1 = right - mid;

    char L[10000];
    char R[10000];

    for (int k = 0; k < l1; k++)
    {
        L[k] = s[left + k];
    }

    for (int k = 0; k < r1; k++)
    {
        R[k] = s[mid + 1 + k];
    }

    int i, j, k;
    i = j = 0;
    k = left;
    while (i < l1 && j < r1)
    {
        if (L[i] - 'a' <= R[j] - 'a')
        {
            s[k] = L[i];
            i++;
        }
        else
        {
            s[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < l1)
    {
        s[k] = L[i];
        i++, k++;
    }
    while (j < r1)
    {
        s[k] = R[j];
        j++, k++;
    }
}

void merge(char s[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge(s, left, mid);
        merge(s, mid + 1, right);

        sort(s, left, mid, right);
    }
}

/*
3
abcabcabc
ba
aeeaaeaeffgg
eag
gfhefhgehfgijijkk
hgk
*/

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int cases = 1; cases <= tc; cases++)
    {
        char s[10000];
        scanf("%s", &s);
        getchar();
        char u[10000];
        scanf("%s", &u);
        getchar();

        char ans[1000] = "";
        int k = 0;
        for (int i = 0; i < strlen(u); i++)
        {
            for (int j = 0; j < strlen(s); j++)
            {
                if (s[j] == u[i])
                {
                    // int index = s[j] - 'a';
                    char temp[1];
                    temp[0] = s[j];
                    // 'b'
                    // "b"

                    // strcat menggabungkan 2 "string", cattonate
                    // definisi string kumpulan character
                    ans[k] = s[j];
                    k++;
                }
            }
        }
        ans[k] = '\0';
        merge(ans, 0, strlen(ans) - 1);
        printf("Case #%d: %s\n", cases, ans);
    }
    return 0;
}