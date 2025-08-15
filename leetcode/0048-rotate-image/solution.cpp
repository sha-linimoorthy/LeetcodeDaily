class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose + reverse rows
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        for(int i=0;i<row_size-1;i++)
        {
            for(int j=i;j<col_size;j++)
            {
                if(i!=j) swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<row_size;i++)
        {
            for(int j=0;j<(col_size/2);j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col_size - j - 1];
                matrix[i][col_size - j -1] = temp;
            }
        }
        
    }
};
