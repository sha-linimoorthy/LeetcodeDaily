class Solution {
public:
    vector<int> addElement(vector<int> &len, int i, int j)
    {
        len[0] = i;
        len[1] = j;
        return len;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> len(2,-1);
        int row_size = mat.size() - 1;
        int col_size = mat[0].size() - 1;
        for(int i=0;i<=row_size;i++)
        {
            for(int j=0;j<=col_size;j++)
            {
                int top = (i > 0)? mat[i-1][j] : -1;
                int bottom = (i < row_size)? mat[i+1][j] : -1;
                int right = (j < col_size)? mat[i][j+1] : -1;
                int left = (j > 0)? mat[i][j-1] : -1;
                if((mat[i][j] > top) && (mat[i][j] > bottom) && (mat[i][j] > left) && (mat[i][j] > right)) 
                {
                    return addElement(len, i, j);
                }  
            }
        }
        return len;
    }
};
