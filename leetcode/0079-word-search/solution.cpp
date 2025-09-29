class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int ind, int& row,int& col, int r, int c)
    {
        if(ind==word.length()) return true;
        if(r>=row || c>=col || r<0 || c<0 || (board[r][c]!=word[ind])) return false;
        char ch = word[ind];
        board[r][c] = '.';
        bool res = solve(board, word, ind+1, row, col, r+1, c) || 
        solve(board, word, ind+1, row, col, r-1, c) || solve(board, word, ind+1, row, col, r, c+1) || solve(board, word, ind+1, row, col, r, c-1);
        board[r][c] = ch;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROW_N = board.size();
        int COL_N = board[0].size();
        for(int i=0; i<ROW_N; i++){
            for(int j=0; j<COL_N; j++){
                if(solve(board, word, 0, ROW_N, COL_N, i, j)) return true;
            }
        }
        return false;
    }
};
