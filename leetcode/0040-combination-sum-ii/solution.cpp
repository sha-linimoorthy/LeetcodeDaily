class Solution {
public:
    void solve(int ind, vector<int>& c, int t, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(t==0) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<c.size();i++) {
            if(i>ind && c[i]==c[i-1]) continue;
            if(c[i]>t) break;
            ds.push_back(c[i]);
            solve(i+1,c,t-c[i],ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, target, ds, ans);
        return ans;
    }
};
