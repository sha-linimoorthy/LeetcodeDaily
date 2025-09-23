class Solution {
public:
    void solve(string s, string op, vector<string>& ans){
        if(s=="") {
            ans.push_back(op);
            return;
        }
        char c = s[0];
        string rest = s.substr(1);
        solve(rest, op+c, ans);
        if(isalpha(c)) {
            if(islower(c)) {
                solve(rest, op+(char)toupper(c), ans);
            }
            else {
                solve(rest, op+(char)tolower(c), ans);
            }
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, "", ans);
        return ans;
    }
};
