#include <stdio.h>

int binary(long long int num){
    double left = 0, right = num + 1;
    long long int temp;
    while(left <= right){
        long long int mid = (right + left) / 2;
        double total =(1.0 / 6 * mid * (mid + 1) * (2 * mid + 1));
        if(total >= num){
            temp = mid;
            right = mid - 1;
        }
        else if(total < num){
            left = mid + 1;
        }
    }
    return temp;
}

int main(){
    int testcase;
    long long int num;

    scanf("%d", &testcase);
    for(int i = 0; i < testcase; i++){
        scanf("%lld", &num);
        printf("Case #%d: %lld\n",i+1, binary(num));
    }

    return 0;
}
