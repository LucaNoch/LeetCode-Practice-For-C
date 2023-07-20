int searchInsert(int* nums, int numsSize, int target){
    int result = 0;

    for (int i = 0; i < numsSize; i++){
        if(nums[i] == target){
            result = i;
            return result;
        }
        else if(nums[i] > target){
            result = i;
            return result;
        }
        else{
            result++;
        }
    }
    return result;
}

/*
int searchInsert(int* nums, int numsSize, int target){
    if(nums[numsSize-1]<target) return numsSize;
    int left=0,right=numsSize-1,mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(nums[mid]<target) left=mid+1;
        else if(nums[mid]>target) right=mid;
        else return mid;
    }
    return right;
}
*/