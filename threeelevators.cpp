#include <stdio.h>

int main() {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);

    
    if (x < 0 || x > 100 || y < 0 || y > 100 || k < 0 || k > 100) {
        printf("Invalid input. Elevator floor numbers must be between 0 and 100.\n");
        return 1; 
    }

    int time = -1; 

    if ((x < k && y > k) || (x > k && y < k)) {
        
        int time_to_first, time_to_second;

        if (x < k) {
            time_to_first = k - x;
        } else {
            time_to_first = x - k;
        }

        if (y < k) {
            time_to_second = k - y; 
        } else {
            time_to_second = y - k;
        }

        if (time_to_first < time_to_second) {
            time = time_to_first;
        } else {
            time = time_to_second;
        }
    }

    printf("%d\n", time);

    return 0;
}
