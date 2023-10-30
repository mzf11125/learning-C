#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to check if a number is a perfect square
int isPerfectSquare(int num) {
    for (int i = 1; i * i <= num; i++) {
        if (i * i == num)
            return 1;
    }
    return 0;
}

// Function to check if a number is a perfect cube
int isPerfectCube(int num) {
    for (int i = 1; i * i * i <= num; i++) {
        if (i * i * i == num)
            return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        printf("Case #%d : ", i);
        if (num < 0) {
            printf("None\n");
        } else {
            if (isPerfectSquare(num)) {
                printf("square ");
            }
            if (isPerfectCube(num)) {
                printf("cubic");
            }
            if (isPrime(num)) {
                printf("prime");
            } else if (!isPerfectSquare(num) && !isPerfectCube(num)) {
                printf("None");
            }
        }
        printf("\n");
    }
    return 0;
}
