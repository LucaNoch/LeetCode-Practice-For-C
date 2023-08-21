typedef struct {
    int val;
    int idx;
} num;

int sortf(void* a, void* b){
    num num1 = *(num*) a;
    num num2 = *(num*) b;
    
    if (num1.val > num2.val) return 1;
    else if (num1.val < num2.val) return -1;
    else
    {
        if (num1.idx > num2.idx) return 1;
        else if (num1.idx < num2.idx) return -1;
        else return 0;
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if (numsSize < 2) return false;
    
    num* nums_with_indices = malloc(sizeof(*nums_with_indices) * numsSize);
    for (int i = 0 ; i < numsSize; ++i)
    {
        nums_with_indices[i].val = nums[i];
        nums_with_indices[i].idx = i;
    }
    
    qsort(nums_with_indices, numsSize, sizeof(*nums_with_indices), sortf);
    
    for (int j = 1; j < numsSize; ++j)
    {
        if (nums_with_indices[j].val == nums_with_indices[j - 1].val &&
           abs(nums_with_indices[j].idx - nums_with_indices[j - 1].idx) <= k) return true;
    }
    
    return false;
}