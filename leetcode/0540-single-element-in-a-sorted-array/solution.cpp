class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = size(nums);
        if(n==1) return nums[n-1];
        if(nums[0]!=nums[1]) return nums[0];
        int left = 1;
        int right = n - 2;
        while(left<=right)
        {
            int mid = (left+right) / 2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]) 
            return nums[mid];
            if((mid%2==0) && nums[mid]==nums[mid+1] || (mid%2!=0) && nums[mid]==nums[mid-1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[n-1]; //nums[n-2] != nums[n-1]
    }
};
