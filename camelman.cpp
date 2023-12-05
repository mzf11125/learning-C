#include <stdio.h>
#include <string.h>


int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }


    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    } else {
        return 0;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        char str[1001];
        scanf("%s", str);

        int length = strlen(str);

       
        int result = isPalindrome(str, 0, length - 1);

        
        printf("Case #%d: %s\n", i, result ? "yes" : "no");
    }

    return 0;
}
