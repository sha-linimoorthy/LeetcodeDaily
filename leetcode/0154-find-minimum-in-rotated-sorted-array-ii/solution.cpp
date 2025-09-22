class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int l =0, r = nums.size() - 1;
        while(l<=r) {
            int m = (l+r) / 2;
            if(nums[m]==nums[l] && nums[m]==nums[r]) { ans = min(nums[m], ans); r--; l++; continue; }
            if(nums[r] >= nums[m]) {
                ans = min(nums[m], ans);
                r = m - 1;
            }
            else l = m + 1;
        }

        return ans;
    }
};
