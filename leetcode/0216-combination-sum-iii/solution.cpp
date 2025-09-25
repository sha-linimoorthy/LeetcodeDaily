class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int k,int n){
        if(i==nums.size()) {
            if(n==0) {
                if(ds.size()==k) ans.push_back(ds);
            }
            return;
        }
        
        if(i<nums.size() && nums[i]<=n) {
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans, k, n-nums[i]);
            ds.pop_back();
        }
        solve(i+1, nums, ds, ans, k, n);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<=9;i++) nums.push_back(i);
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, nums, ds, ans, k, n);
        return ans;
    }
};
