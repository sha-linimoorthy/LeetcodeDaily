class Solution {
public:
    void solve(vector<int> inp, vector<int> outp, vector<vector<int>>& ans, int i)
    {
        if(i==inp.size()){
            ans.push_back(outp);
            return;
        }
        solve(inp, outp, ans, i+1);
        outp.push_back(inp[i]);
        solve(inp, outp, ans, i+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, vector<int>{}, ans, 0);
        return ans;
    }
};
