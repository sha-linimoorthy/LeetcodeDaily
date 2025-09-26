class Solution {
public:
    bool isPali(string s) {
        int n = s.length();
        for(int i=0;i<(n/2);i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    void solve(string& s, int indx, vector<vector<string>>& ans, vector<string>& ds)
    {
        if(indx==s.length())
        {
            ans.push_back(ds);
            return;
        }
            
        for(int i=indx; i<s.size(); i++){
            string str = s.substr(indx, i-indx+1);
            if(isPali(str)){
                ds.push_back(str);
                solve(s, i+1, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s, 0, ans, ds);
        return ans;
    }
};
