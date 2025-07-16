void checkZeroes(int ** matrix, int i, int j, int *col0)
{
    if(matrix[i][j]==0)
    {
        matrix[i][0]=0;
        if(j==0) 
        {
            *col0=0;
        }
        else
        {
            matrix[0][j]=0;
        }
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int col0=1;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<*matrixColSize;j++)
        {
            checkZeroes(matrix,i,j,&col0);
        }
    }

    for(int i=matrixSize-1;i>0;i--)
    {
        for(int j=*matrixColSize-1;j>0;j--)
        {
            if(!matrix[i][0] || !matrix[0][j])
            {
                //printf("yes");
                matrix[i][j] = 0;
            }
        }
    }

    if(!matrix[0][0])
    {
       //printf("yes");
        for(int j=0;j<*matrixColSize;j++) matrix[0][j] = 0;
    }
    if(!col0)
    {
        printf("yes");
        for(int i=0;i<matrixSize;i++) matrix[i][0] = 0;
    }
    
}


