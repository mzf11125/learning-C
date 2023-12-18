#include <stdio.h>
int fiboCalls[31];
int fibo(int n, int *count) {
	
	(*count)++;
    if(n==0 || n==1) //If n is 0 or 1
        return n; //return n = the number itself
    else //else return the sum of the previous two numbers
        return fibo(n-1, count)+fibo(n-2, count);
}

int main() {
    int T;
    scanf("%d", &T);getchar();
    for (int i = 1; i <= 30; i++) {
        fiboCalls[i] = -1; 
    }
    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);getchar();
        int count = 0;
		fibo(n, &count);
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}