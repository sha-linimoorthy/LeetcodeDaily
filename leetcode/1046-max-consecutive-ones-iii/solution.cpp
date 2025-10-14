class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int zeroCount = 0;
        int maxLen = 0;
        while(r<n){
            if(nums[r]==0) zeroCount++;
            if(zeroCount > k) {
                if(nums[l]==0) zeroCount--;
                l++;
            }
            else{
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
