#include <stdio.h>
#include <string.h>

int tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int isSpecialPalindrome(const char *s) {
    int len = strlen(s);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        // Skip non-alphanumeric characters and underscores at the beginning
        while (i < len && (s[i] == '_' || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) {
            i++;
        }

        // Skip non-alphanumeric characters and underscores at the end
        while (j >= 0 && (s[j] == '_' || (s[j] >= '0' && s[j] <= '9') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))) {
            j--;}

        // Compare characters in a case-insensitive manner
        if (i < len && j >= 0) {
            if (tolower(s[i]) != tolower(s[j])) {
                return 0; // Not a special palindrome
            }
        }

        i++;
        j--;
    }

    return 1; // Special palindrome with underscore at the beginning or end
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // Remove the newline character

    if (isSpecialPalindrome(input_string)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
