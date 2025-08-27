class Solution {
public:
    int findMaxIndx(vector<vector<int>> & mat, int col)
    {
        int max = INT_MIN;
        int index = -1;
        for(int i=0; i<mat.size(); i++)
        {
            if(mat[i][col] > max) 
            {
                max = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row_size = mat.size();
        int col_size = mat[0].size();
        int left = 0;
        int right = col_size - 1;

        while(left<=right)
        {
            int mid = (left+right) / 2;
            int row = findMaxIndx(mat, mid);
            int left_val = (mid >= 1) ? mat[row][mid - 1] : -1;
            int right_val = (mid < (col_size - 1)) ? mat[row][mid + 1] : -1;
            if((mat[row][mid] > left_val) && (mat[row][mid] > right_val))
            {
                return {row, mid};
            }
            else if(left_val > mat[row][mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }

        }
        return {-1, -1};
    }
};
