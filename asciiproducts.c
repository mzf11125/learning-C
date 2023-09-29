#include <stdio.h>

int main() {
    char myChar1, myChar2;
    
    scanf("%c %c", &myChar1, &myChar2);
    
    long long myInt = ((long long)myChar1) * ((long long)myChar2);

    printf("%.0lld\n", myInt);

    return 0;
}
