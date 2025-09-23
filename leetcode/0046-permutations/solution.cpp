class Solution {
public:
    void findPermute(int indx, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(indx==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=indx; i<nums.size(); i++){
            swap(nums[i],nums[indx]);
            findPermute(indx+1, nums, ans);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermute(0, nums, ans);
        return ans;
    }
};
