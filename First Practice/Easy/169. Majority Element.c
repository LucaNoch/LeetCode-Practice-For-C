int majorityElement(int* nums, int numsSize){
    int result = nums[0], con = 1;

    for(int i = 1; i < numsSize; i++){
        if(result == nums[i])
            con++;
        else if(con > 0)
            con--;
        else{
            result = nums[i];
            con ++;
        }
    }
    return result;
}
/*
int majorityElement(int* nums, int numsSize){

    int candidate = 0;
    int counter = 0;

    for(int i = 0; i < numsSize; i++){
        if(counter  == 0){
            candidate = nums[i];
        }
        counter += (candidate == nums[i]) ? 1 : -1;
    }
    return candidate;
}
*/