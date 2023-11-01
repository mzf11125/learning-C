#include <stdio.h>
#include <string.h>

int all_number_or_char(const char S[]) {
    int n = strlen(S);
    for (int i = 0; i < n; i++) {
        if (!((S[i] >= '0' && S[i] <= '9') || (S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))){
            return 0; // False
        }
    }
    return 1; // True
}

int num_of_dot(const char S[]) {
    int n = strlen(S);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (S[i] == '.') {
            sum++;
        }
    }

    return sum;
}

void solution() {
    char S[201]; // Increased buffer size to accommodate up to 200 characters
    scanf("%s", S);

    if (all_number_or_char(S) && num_of_dot(S) == 5) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        solution();
    }

    return 0;
}
