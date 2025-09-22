class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size() - 1;
        int l = 0;
        int ans = INT_MAX;
        while(l<=r) {
            int m = (l+r) / 2;
            if(nums[r] >= nums[m]){
                ans = min(ans,nums[m]);
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
