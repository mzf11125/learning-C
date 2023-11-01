#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverseString(char str[], int left, int right) {
    if (left < right) {
        // Swap the characters at left and right indices
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Recursively reverse the rest of the string
        reverseString(str, left + 1, right - 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        char input[1001];  // Assuming the maximum length of input string is 1000
        scanf(" %[^\n]s", input); // Read the input string

        // Call the reverseString function to reverse the input
        reverseString(input, 0, strlen(input) - 1);

        // Print the reversed string for this testcase
        printf("Case #%d: %s\n", caseNum, input);
    }

    return 0;
}
