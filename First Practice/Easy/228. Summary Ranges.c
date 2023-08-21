// Solution 1 (Not By Myslef)
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    char** ret = NULL;
    if (numsSize == 1)
    {
        int stlen = (log10(INT_MAX) + 3); // enough space for ints of max length, null terminator, and neg sign
        ret = (char**) malloc(sizeof(char*) * numsSize);
        
        ret[0] = (char*) malloc(sizeof(char) * stlen);
        sprintf(ret[0], "%d", nums[0]);
        
        (*returnSize)++;
    }
    else if (numsSize > 1)
    {
        int i, start, j;
        int stlen = ((log10(INT_MAX) + 2) * 2) + 3; // enough space for ints of max length, null terminator, arrow, and neg sign
        ret = (char**) malloc(sizeof(char*) * numsSize);
        
        for (i = 1, start = nums[0], j = 0; i < numsSize; i++)
        {
            if (nums[i] != (nums[i - 1] + 1))
            {
                ret[j] = (char*) malloc(sizeof(char) * stlen);
                (nums[i - 1] - start > 0) ? sprintf(ret[j++], "%d->%d", start, nums[i - 1]) : sprintf(ret[j++], "%d", nums[i - 1]);
                start = nums[i];
                (*returnSize)++;
            }
        }
        
        (*returnSize)++;
        ret[j] = (char*) malloc(sizeof(char) * stlen);
        (nums[i - 1] - start > 0) ? sprintf(ret[j++], "%d->%d", start, nums[i - 1]) : sprintf(ret[j++], "%d", nums[i - 1]);
    }
    
    return ret;
}

// Solution 2 (Not By Myslef)
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    int start = 0;
    char** final_arr = (char**)malloc(20*sizeof(char*));
    int count =0;
        for (int k=0;k<numsSize;k++){
            if (k==0 || nums[k]-1 > nums[k-1]){ // did "-1" here, since the number will not be stored (too large)
                start=nums[k];
            }
            if (k==numsSize-1 || nums[k]+1 < nums[k+1]){ // we are at the finish line
                // printf("[%d..%d]\n",start,nums[k]);
                final_arr[count]= (char*) malloc(28*sizeof(char));
                if (start<nums[k]){
                    snprintf(final_arr[count],28,"%d->%d",start,nums[k]); 
                }
                else 
                    snprintf(final_arr[count],28,"%d",start);
                printf("%s\n",final_arr[count]);
                count++;
            }
        }
    *returnSize = count;
    return final_arr;
    
}