class Solution {
public:
    void solve(int n, int col, vector<vector<string>>& ans, vector<string>& board, vector<int>& left, vector<int>& lowerDiagonal, vector<int>& upperDiagonal)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int r=0; r<n; r++)
        {
            if(left[r]==0 && upperDiagonal[(n-1)+(col-r)]==0 && lowerDiagonal[r+col]==0){
                board[r][col]='Q';
                left[r]=1;
                upperDiagonal[(n-1)+(col-r)]=1;
                lowerDiagonal[r+col]=1;
                solve(n, col+1, ans, board, left, lowerDiagonal, upperDiagonal);
                board[r][col]='.';
                left[r]=0;
                upperDiagonal[(n-1)+(col-r)]=0;
                lowerDiagonal[r+col]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n,s);
        vector<int> left(n, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        solve(n, 0, ans, board, left, lowerDiagonal, upperDiagonal);
        return ans;
    }
};
