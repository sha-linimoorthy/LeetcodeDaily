class Solution {
public:
    void solve(int& n, int& k, vector<int>& ds, vector<vector<int>>& ans, int indx)
    {
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }

        for(int i=indx; i<=n; i++){
            ds.push_back(i);
            solve(n, k, ds, ans, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(n, k, ds, ans, 1);
        return ans;
    }
};
