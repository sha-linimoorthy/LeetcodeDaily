class Solution {
public:
    int solve(vector<int>& nums, int k){
        int r = 0, l = 0, count = 0;
        unordered_map<int, int> mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=k){
                count += (r-l+1);
            }
            r++;
        } 
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};
