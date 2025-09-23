class Solution {
public:
    void solve(vector<int> inp, vector<int> outp, vector<vector<int>>& ans)
    {
        if(inp.size()==0){
            ans.push_back(outp);
            return;
        }
        vector<int> op1(outp);
        vector<int> op2(outp);
        op2.push_back(inp[0]);
        inp.erase(inp.begin()+0);
        solve(inp, op1, ans);
        solve(inp, op2, ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, vector<int>{}, ans);
        return ans;
    }
};
