class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int left = 0, right = (row_size * col_size) - 1;

        while(left<=right)
        {
            int mid = (left+right) / 2;
            int row =  mid / col_size;
            int col =  mid % col_size;
            if(matrix[row][col]==target) return true;
            if(matrix[row][col] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};
