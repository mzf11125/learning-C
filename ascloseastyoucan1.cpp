#include <stdio.h>

// This function finds the index from the data A such that if we sum all the elements from 1st index of A until Yth index, we will get a number that has the smallest difference with M and is less than or equal to M.
void getIndex(long long int *arr, int size, long long int value){
    int l = 0;
    int r = size - 2;
    // If the last element of the array is less than or equal to the given value, return the index of the last element plus 1.
    if(arr[r+1] <= value){
        printf("%d\n", r+2);
        return;
    }
    // Perform binary search to find the index of the element that has the smallest difference with the given value and is less than or equal to the given value.
    while(l <= r){
        int m = l + (r - l) / 2;

        if(arr[m] <= value && value < arr[m + 1]){
            printf("%d\n", m+1);
            return;
        }else if(arr[m] < value){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    // If no such element exists, return -1.
    printf("-1\n");
}

int main(){
    int size;
    scanf("%d", &size);getchar();
    long long int data[size+5];
    long long int index[size+5];
    
    // Read the input data and calculate the prefix sum of the array.
    scanf("%lli", &data[0]);
    for(int i = 1; i < size; i++){
        long long int temp;
        scanf("%lli", &temp);
        data[i] = temp + data[i-1];
    }
    
    int tc;
    scanf("%d", &tc);
    // For each test case, read the value and call the getIndex function to find the index of the element.
    for(int i = 0; i < tc; i++){
        long long int num;
        scanf("%lli", &num);getchar();
        printf("Case #%d: ", i+1);
        getIndex(data, size, num);
    }
    
    return 0;
}
