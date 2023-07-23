int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int carry = 1;
    int* result = malloc(digitsSize * sizeof(int));
    *returnSize = digitsSize;
    int i;
    for (i = digitsSize - 1; i >= 0; i--) 
    {
        int sum = digits[i] + carry;
        carry = sum / 10;
        result[i] = sum % 10;
    }
    if (carry == 1) 
    {
        *returnSize = digitsSize + 1;
        result = realloc(result, (*returnSize) * sizeof(int)); 
        result[0] = 1;
        printf("r[0]=%d ",result[0]);
        for (int i = 1; i<(digitsSize+1); i++) 
        {
            result[i] = 0;
            printf("r[%d]=%d ",i,result[i]);
        }
    }
    return result;
}