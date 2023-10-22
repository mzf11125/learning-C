#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char str[N];
    scanf(" %s", str);  

    for (int i = 0; i < M; i++) {
        int que;
        scanf("%d", &que);
        
        if (str[que] >= 'a' && str[que] <= 'z') {
            str[que] = str[que] - 'a' + 'A'; 
        } else {
            str[que] = str[que] - 'A' + 'a'; 
        }
    }

    printf("%s\n", str);  

    return 0;
}
