class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        int l =0, r = 0;
        while(r<nums.size())
        {
            curr_sum += nums[r];
            if(curr_sum>max_sum) 
            {
                max_sum = curr_sum;
            }
            if(curr_sum<0) {
                curr_sum=0;
                l = r+1;
            }
            r++;
        }
        return max_sum;
    }
};
