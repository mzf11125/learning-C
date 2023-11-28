#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        char str[1001];
        scanf("%s", str);

    
        reverse(str);


        printf("Case #%d : %s\n", i, str);
    }

    return 0;
}
