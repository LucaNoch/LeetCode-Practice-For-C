// Solution 1

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        int buffer = abs(nums[i]);

        if(nums[buffer - 1] > 0){
            nums[buffer - 1] = -1 * nums[buffer - 1];
        }
    }

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            *returnSize = *returnSize + 1;
        }
    }
    
    int* return_array = (int*)malloc(*returnSize * sizeof(int));
    int j = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            *(return_array + j) = i + 1;
            j++;
        }
    }

    return return_array;
}
