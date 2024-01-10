#include <stdio.h>

#define ll long long

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        ll n, m;
        ll flag = 0;
        ll count = 0;
        ll length = 0;
        scanf("%lld %lld", &n, &m);
        ll a[10005];
        for (int ii = 0; ii < n; ii++)
        {
            scanf("%lld", &a[ii]);
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
        {
            printf("Case #%d: -1\n", i + 1);
        }
    }
    return 0;
}
