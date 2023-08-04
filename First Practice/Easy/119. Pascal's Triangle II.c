int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex+1;
    int* ret = malloc(*returnSize*sizeof(int));
    ret[0]=1;
    int i;
    //Use binomial coefficients
    for(i=1;i<rowIndex;i++)
    {
        //we are using this typecast (long long) for larger rowIndex's
        ret[i]=(long long)ret[i-1]*(rowIndex-i+1)/i;
    }
    ret[rowIndex]=1;
    return ret;
}



int* getRow(int rowIndex, int* returnSize){
  *returnSize = rowIndex + 1;
  int *row = malloc(*returnSize * sizeof(int));
  row[0] = 1;

  int mid = (*returnSize / 2) + 1;
  for (int i = 1; i < mid; i++) {
    row[i] = (int)((long long)row[i - 1] * (rowIndex + 1 - i) / i);
  }

  for (int i = mid; i < *returnSize; i++) {
    row[i] = row[*returnSize - i - 1];
  }

  return row;
}