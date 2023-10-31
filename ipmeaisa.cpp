#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool all_num_or_dot(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (!(('0' <= s[i] && s[i] <= '9') || s[i] == '.')) {
            return false;
        }
    }
    return true;
}

int number_of_dot(char s[]) {
    int n = strlen(s);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') sum++;
    }
    return sum;
}

bool pos_dot(char s[]) {
    int n = strlen(s);

    if (s[0] == '.' || s[n - 1] == '.') {
        return false;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '.' && s[i + 1] == '.') {
            return false;
        }
    }
    return true;
}

void solve(char s[]) {
    if (number_of_dot(s) == 5 && all_num_or_dot(s) && pos_dot(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        char s[200];
        scanf("%s", s);
        printf("Case #%d: ", i);
        solve(s);
    }

    return 0;
}
