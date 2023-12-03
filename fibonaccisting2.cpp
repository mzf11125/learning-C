#include <stdio.h>
#include <string.h>

// Function to generate Fibonacci-like sequence of strings
void fibString(char *s0, char *s1, int n, char *result) {
    int i = 0;
    while (n--) {
        if (i++ % 2) {
            strcat(result, s0);
            strcat(result, s1);
        } else {
            strcat(result, s1);
            strcat(result, s0);
        }

        // Update s0 and s1
        char temp[100]; // Adjust the size based on your needs
        strcpy(temp, s0);
        strcpy(s0, s1);
        strcpy(s1, temp);
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        char s0[100], s1[100];

        scanf("%d %s %s", &n, s0, s1);

        char result[1000]; // Adjust the size based on your needs
        result[0] = '\0';  // Initialize result as an empty string

        // Generate Fibonacci-like sequence of strings
        fibString(s0, s1, n, result);

        // Print each character in the generated string
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < strlen(result)-2; j++) {
            printf("%c", result[j]);
        }
        printf("\n");
    }

    return 0;
}
