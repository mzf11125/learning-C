#include <stdio.h>
#include <string.h>

// Sieve of eratosthenes
int prima[100001];

void sieve()
{
    for (int i = 2; i * i < 100001; i++)
    {
        if (prima[i] == 1)
        {
            for (int j = i * i; i < 100001; j += i)
            {
                prima[j] = 0;
            }
        }
    }
}

int main()
{
    memset(prima, 1, sizeof(prima));
    for (int i = 0; i <= 100000; i++)
    {
        prima[i] = 1;
    }
    sieve();
    int n;
    scanf("%d", &n);

    return 0;
}