int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    //created 2D array and that's why used 2 astricks(*) becuase each row contain one pointer that point the 1D array
    int **array2D=(int**)malloc(numRows * sizeof(int**));
    // created returncolumnsizes array for each row
    *returnColumnSizes=(int*)malloc(numRows * sizeof(int));
    for(int i=0;i<numRows;i++){
        array2D[i]=(int*)malloc(numRows * sizeof(int));
        // creating the size of rows
        (*returnColumnSizes)[i]=i+1;
        array2D[i][i]=array2D[i][0]=1;
        for(int j=1; j<i; j++) {
            array2D[i][j]=array2D[i-1][j]+array2D[i-1][j-1];
        }
    }
    *returnSize=numRows;
    return array2D;
}

/*
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows ;
    *returnColumnSizes = (int *)malloc(numRows *sizeof(int));
    int **arr = (int **)malloc(numRows *sizeof(int *));
    for(int i = 0 ;i < numRows ; i++){
        (*returnColumnSizes)[i]=i+1;
        arr[i]= (int *)malloc((i+1)*sizeof(int));
        arr[i][0]= 1 ;
        for(int j = 1 ; j < i ; j++){
            arr[i][j]= arr[i-1][j-1]+arr[i-1][j];
        }
        arr[i][i]= 1 ;
    }
    return arr;
}
*/