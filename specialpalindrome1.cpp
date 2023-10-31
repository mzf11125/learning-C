#include <stdio.h>
#include <string.h>

int isSpecialPalindrome(char *str) {
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i] && str[i] != '_' && str[len - 1 - i] != '_') {
            return 0; // Not a Special Palindrome
        } else if (str[i] == '_' && str[i + 1] == '_') {
            return 0; // Two underscores are next to each other, so it's not a Special Palindrome
        }
    }
    
    return 1; // It is a Special Palindrome
}

int main() {
    char sentence[51]; // Maximum length of the sentence is 50 characters
    
    // Read the input string
    scanf("%s", sentence);
    
    if (isSpecialPalindrome(sentence)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
