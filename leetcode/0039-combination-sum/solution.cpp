class Solution {
public:
    void solve(vector<int>& c, int t, int i, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(i==c.size()) {
            if(t==0)
            ans.push_back(ds);
            return;
        }
        if(c[i]<=t) {
            ds.push_back(c[i]);
            solve(c, t-c[i], i, ds, ans);
            ds.pop_back();
        }
        solve(c, t, i+1, ds, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, 0, ds, ans);
        return ans;
    }
};
