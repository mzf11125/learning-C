#include <stdio.h>
#include <string.h>

void generateFiboString(int n, char a, char b) {
    char fiboString[1000];
    fiboString[0] = a;
    fiboString[1] = b;

    for (int i = 2; i < n; i++) {
        fiboString[i] = fiboString[i-1] + fiboString[i-2]; 
        fiboString[i] = fiboString[n];
    }


    printf("%s\n", fiboString[n]);
}

int main() {
    int t; // number of test cases
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n; // length of the fibo string
        char a, b; // characters a and b
        scanf("%d %c %c", &n, &a, &b);  // Switched a and b here

        printf("Case #%d: ", i);
        generateFiboString(n, b, a);  // Switched a and b here
    }

    return 0;
}
