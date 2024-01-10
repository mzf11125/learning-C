#include <stdio.h>

int main()
{
    long long tc;
    scanf("%lld", &tc);
    for (int i = 0; i < tc; i++)
    {
        long long n, m;
        long long flag = 0;
        long long count = 0;
        long long length = 0;
        scanf("%lld %lld", &n, &m);
        long long a[10005];
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &a[j]);
        }
        for (int j = 0; j < n; j++)
        {
            flag += a[j];
            count++;
            while (flag > m)
            {
                flag -= a[j - count + 1];
                count--;
            }
            if (count > length)
            {
                length = count;
            }
        }
        if (length > 0)
        {
            printf("Case #%d: %lld\n", i + 1, length);
        }
        else
            printf("Case #%d: -1\n", i + 1);
    }
    return 0;
}
