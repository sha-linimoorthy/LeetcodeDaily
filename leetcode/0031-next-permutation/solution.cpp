class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = size(nums);
        int breakIndx = -1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                breakIndx = i;
                break;
            }
        }

        if(breakIndx == -1) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[breakIndx])
            {
                swap(nums[i],nums[breakIndx]);
                break;
            }
        }

        reverse(nums.begin() + breakIndx + 1, nums.end());
        
    }
};
