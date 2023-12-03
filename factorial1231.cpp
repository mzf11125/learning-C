//Factorial

#include <stdio.h>
#include <string.h>



int factorial (int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial (n - 1);
}


int main ()
{
    int tc, count, n[100];
    
    if (tc > )
    for(int i = 0; i < tc; i++){
        scanf("%d", &count);
        for (int j = 0; j < count; j++)
        {
            scanf ("%d", &n[j]);   
        }
    }
    
    printf ("Factorial of %d is %d\n", n, factorial (n));
    return 0;
}