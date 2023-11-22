//fibonacci
#include<stdio.h>


int fib(int n)
{
    // if(n==0)
    //     return 0;
    // else if(n==1)
    //     return 1;
    if(n==0 || n==1) //If n is 0 or 1
        return n; //return n = the number itself
    else //else return the sum of the previous two numbers
        return(fib(n-1)+fib(n-2));
}

int main()
{
    int n,i;
    // printf("Enter the number of terms: ");
    scanf("%d",&n);
    // printf("Fibonacci Series: ");
    for(i=0;i<n;i++)
        printf("%d ",fib(i));
    return 0;
}
