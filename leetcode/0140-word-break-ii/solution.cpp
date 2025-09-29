class Solution {
public:
    void solve(string& s, vector<string>& wordDict, vector<string>& ans, int indx, string str){
        if(indx==s.length()) {
            str.resize(str.size()-1);
            ans.push_back(str);
            return;
        }
        for(int i=indx; i<s.length(); i++) {
            string ss = s.substr(indx, i-indx+1);
            bool ispres = false;
            for(string word: wordDict) {
                if(word==ss) {
                    ispres = true;
                    break;
                }
            }
            if(ispres) {
                int len = str.size();
                str+=ss; str+=" ";
                solve(s, wordDict, ans, i+1, str);
                str.erase(len);// erase what added
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        solve(s, wordDict, ans, 0, "");
        return ans;
    }
};
