class Solution {
public:
    void solve(string& s, int indx, vector<string>& ans, string ds, unordered_map<char,string>& mp)
    {
        if(indx==s.length()){
            ans.push_back(ds);
            return;
        }
        char ch = s[indx];
        for(char combi: mp[ch])
        {
            ds+=combi;
            solve(s, indx+1, ans, ds, mp);
            ds.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits=="") return ans;
        unordered_map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        solve(digits, 0, ans, "",mp);
        return ans;
    }
};
