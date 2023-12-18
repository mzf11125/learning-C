#include <stdio.h>

int main(){
    // bisa dilakukan hanya jika sudah terurut
    // kalau gak terurut gak bisa
    // 0 1 2 3 4 5 6 7 8 9
    // angka berapa yang dicari : 7
    // left, right dan mid
    // left = 0
    // right = 9
    // mid = 4
    // O(Log(N)) -> cepet banget
    // dia tidak perlu mencari semua satu satu
    // O(N) -> Linear search 10
    // Binary Search -> 4
    // diatas 10^8
    int arr[] = {0,1,4,7,10,18,22,69,120,189};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 18;
    int left = 0, right = size-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == target){
            printf("ADA\n");
            printf("Di index ke : %d\n",mid);
            break;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else if(arr[mid] > target){
            right = mid - 1;
        }
    }
    if(left > right){
        printf("TIDAK ADA!\n");
    }
    return 0;
}