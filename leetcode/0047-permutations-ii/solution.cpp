class Solution {
public:
    void findPermute(vector<int>& nums, vector<int> v, vector<vector<int>>& ans, int freq[])
    {
        if(v.size()==nums.size()) {
            bool pres = false;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==v) {pres = true; break; }
            }
            if(!pres)
            ans.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] =1;
                v.push_back(nums[i]);
                findPermute(nums, v, ans, freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        const int n = nums.size();
        int freq [n]; for(int i=0;i<n;i++) freq[i] = 0;
        findPermute(nums, vector<int>{}, ans, freq);
        return ans;
    }
};
