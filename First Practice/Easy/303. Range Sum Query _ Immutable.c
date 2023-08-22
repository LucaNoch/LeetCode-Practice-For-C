typedef struct {
    int* list;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = (NumArray*) malloc(sizeof(NumArray));
    ret->list = (int*) malloc(sizeof(int)*numsSize);
    int sum = 0;
    int i;
    for(i=0;i<numsSize;i++){
        sum += nums[i];
        ret->list[i] = sum;
    }

    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return left > 0 ? obj->list[right] - obj->list[left-1] : obj->list[right];
}

void numArrayFree(NumArray* obj) {
    free(obj->list);
    free(obj);
}

/*
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/

/*
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/