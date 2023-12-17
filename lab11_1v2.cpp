#include <stdio.h>

double totalFunc(double num){
    double total = 1.0/6.0 * num * (num + 1) * (2 * num + 1);
    return total;
}

double binarySearch(double left, double right, double target){
    double temp2;
    while (left <= right){
        unsigned long long mid = (left + right)/2;
        double temp = totalFunc(mid);
        if (temp>=target){
            temp2 = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }

    return temp2;
}

int main(){
    int tc;
    scanf("%d", &tc);

    for (int k=1; k<=tc; k++){
        double target;
        scanf("%lf", &target);

        double maxNum = binarySearch(0, 1000000000000000001, target);

        printf("Case #%d: %.0lf\n", k, maxNum);
    }
    return 0;
}