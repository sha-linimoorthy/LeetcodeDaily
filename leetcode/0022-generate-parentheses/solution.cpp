class Solution {
public:
    void solve(int o, int c, string op, vector<string>& ans){
        if(o==0 && c==0){
            ans.push_back(op);
            return;
        }
        if(o) solve(o-1, c, op+'(', ans);
        if(c>o) solve(o, c-1, op+')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string op = "";
        solve(open, close, op, ans);
        return ans;
    }
};
