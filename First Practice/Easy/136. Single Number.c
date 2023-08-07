int singleNumber(int* nums, int numsSize){
   
    int uniqNum = 0;
    
    for (int idx = 0; idx < numsSize; idx++) {    
        uniqNum ^= nums[idx];  
        //XOR運算特性，a ^ 0 = a：任何數與0 做XOR等於自己。a ^ a = 0：相同的數做XOR等於0。
    } 
    return uniqNum;
}