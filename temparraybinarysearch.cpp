int func(int* nums, int mid, int size, int target) {
    if(size == 1){
        if(nums[0] == target){
            return true;
        }
        else{
            return false;
        }
    }
    int leftArray[100];
    int rightArray[100];
    int leftSize = 0, rightSize = 0;
    for (int left = 0; left <= mid; left++) {
        leftArray[left] = nums[left];
        leftSize++;
        // printf("%d\n", leftArray[left]);
    } 
    // printf("==");

    for (int right = mid+1; right < size; right++) {
        rightArray[right] = nums[right];
        rightSize++;
        // printf("%d\n", rightArray[right]);
    }
    int leftMid = (leftSize - 1) / 2;
    int rightMid = (rightSize - 1)/2;
    printf("%d\n", leftMid);
    printf("%d\n", rightMid);
    return func(leftArray, leftMid, leftSize, target) || func(rightArray , rightMid, rightSize, target);
}

int search(int* nums, int numsSize, int target) {
    int size = numsSize;
    int mid = (size - 1) / 2;

    int result = func(nums, mid, size, target);
    // printf("%d\n", result);

    // printf("%d", mid);
    return 0;
}