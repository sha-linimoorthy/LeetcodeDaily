class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> qp;
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                qp.push(matrix[i][j]);
                if(qp.size()>k) qp.pop();
            }
        }
        return qp.top();
    }
};
