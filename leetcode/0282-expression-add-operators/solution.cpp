class Solution {
public:
    void solve(string& s, int& k, vector<string>& ans, int ind, string op, long long val, long long preVal)
    {
        if(ind==s.length()){
            if(val==k) ans.push_back(op);
            return;
        }
        for(int i=ind;i<s.length();i++) {
        string ch = s.substr(ind, i-ind+1);
        if(ch.size()>1 && ch[0]=='0') break;
        long long currVal = stoll(ch);
        if(ind!=0){
            solve(s, k, ans, i+1, op+'+'+ch, val+currVal, currVal);
            solve(s, k, ans, i+1, op+'-'+ch, val-currVal, -currVal);
            solve(s, k, ans, i+1, op+'*'+ch, val-preVal+preVal*currVal, preVal*currVal);
        }
        else {
            solve(s, k, ans, i+1, op+ch, currVal, currVal);
        }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, ans, 0, "", 0, 0);
        return ans;
    }
};
