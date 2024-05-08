// Soulation 1  
int missingNumber(int* nums, int numsSize) {
    int sum=0;
    int sum_nums=(numsSize*(numsSize+1))/2;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    return sum_nums-sum;
}

// Soulation 2 XOR

int missingNumber(int* nums, int numsSize) {
    int figure = numsSize;

    for (int i = 0; i < numsSize; ++i) {
        figure ^= i ^ nums[i];
    }
    return figure;
}
