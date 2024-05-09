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

// Solution 2  Less memory

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    int temp = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        temp = abs(nums[i]) - 1;
        nums[temp] = abs(nums[temp]) * -1;
    }
    
    int insert_index = 0;

    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            ++*returnSize;
            nums[insert_index++] = i + 1;
        }
    }
    
    return nums;
}

// Solution 3

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int m;
    for (int c = 0; c < numsSize; c++) {
        m = abs(nums[c]) - 1;
        nums[m] = -1 * abs(nums[m]);
    }

    *returnSize = 0;
    for (int c = 0; c < numsSize; c++)
        if (nums[c] > 0)
            (*returnSize)++;
    
    int *ret = (int *) calloc (*returnSize, sizeof (int));
    int s = 0;
    for (int c = 0; c < numsSize; c++)
        if (nums[c] > 0)
            ret[s++] = c + 1;
    
    return ret;
}
