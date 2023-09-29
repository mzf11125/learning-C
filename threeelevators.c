#include <stdio.h>

int main() {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);


    if ((x <= k) && (y>=k)) {
        int time_to_first;

        if (x < k) {
            time_to_first = k - x;
        } else {
            time_to_first = x - k;
        }
        printf("%d\n",time_to_first);
    }
    else{
        printf("-1\n");
    }


    return 0;
}
