#include <stdio.h>

void changeLetterCapitalization(char* string, char N) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == N) {
            if (N >= 'a' && N <= 'z') {
                string[i] = N - 'a' + 'A'; // Change lowercase to uppercase
            } else if (N >= 'A' && N <= 'Z') {
                string[i] = N - 'A' + 'a'; // Change uppercase to lowercase
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        char string[100]; // specify the size of the string array

        scanf(" %[^\n]", string); // add a space before %[^\n] to consume the newline character

        char N; // Declare N as a char, not int
        scanf(" %c", &N); // add & before N to pass its address to scanf

        if ((N >= 'a' && N <= 'z') || (N >= 'A' && N <= 'Z')) {
            changeLetterCapitalization(string, N); // Correct function name
        }

        printf("%s\n", string); // Print the modified string
    }

    return 0;
}
