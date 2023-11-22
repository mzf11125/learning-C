#include<stdio.h>

int sequence[100]; 

int fib(int n)
{
    if(n==0 || n==1)
        return sequence[n];
    else 
        return(fib(n-1)+fib(n-2));
}

int main()
{
    int n, k;
    scanf("%d %d",&sequence[0], &sequence[1]); 
    scanf("%d", &k); 
    printf("%d\n",fib(k)); 
    return 0;
}