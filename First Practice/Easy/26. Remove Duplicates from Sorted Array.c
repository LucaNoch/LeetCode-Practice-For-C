int removeDuplicates(int* nums, int numsSize){
  
  int result = 0;
  
  for(int i = 0; i < numsSize; i++){
    if(nums[i] != nums[result]){
      result++;
      nums[result] = nums[i];
    }
  }
  return result + 1;
}
/*
int removeDuplicates(int* nums, int numsSize){
    int s_i = 0;
    int i = 0;

    for (i = 1; i<numsSize; i++) {
        if (nums[s_i] != nums[i]) {
            nums[++s_i] = nums[i];
        }
    }

    return (s_i+1);
}
*/