class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int top = 0;
        int left = 0;
        int bottom = row_size -1;
        int right = col_size -1;
        vector<int> result;

        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                result.emplace_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++)
            {
                result.emplace_back(matrix[i][right]);
            }
            right--;

            //one line
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                    {
                        result.emplace_back(matrix[bottom][i]);
                    }
                bottom--;
            }

            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    result.emplace_back(matrix[i][left]);
                }
                left++;
            }

        }

       return result; 
    }
};
