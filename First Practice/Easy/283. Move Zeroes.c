// Solution 1
void moveZeroes(int* nums, int numsSize) {
    int j = 0;

    for (int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
    memset(nums + j, 0, (numsSize - j) * sizeof(int));
}

// Solution 2
void moveZeroes(int* nums, int numsSize) {
    int j = 0;

    for (int i = 1; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < numsSize; i++) {
        nums[i] = 0;
    }
}
