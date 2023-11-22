#include <stdio.h>


int main(){
    int x, y, t, a, b, c;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        scanf("%d %d", &x, &y);
        a = x + y;
        b = x - y;
        c = x * y;
        if (a > b && a > c){
            printf("Case #%d: %d\n", i, a);
        } else if (b > a && b > c){
            printf("Case #%d: %d\n", i, b);
        } else {
            printf("Case #%d: %d\n", i, c);
        }
    }

    return 0;
}