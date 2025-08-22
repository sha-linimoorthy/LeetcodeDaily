class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left<=right)
        {
            int mid = (left+right) / 2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[left] && nums[mid]==nums[right])
            {
                left++;
                right--;
                continue;
            }
            // is left sorted
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && nums[mid] >= target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            //right must be sorted
            else
            {
                if(nums[mid] <= target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return false;
        
    }
};
