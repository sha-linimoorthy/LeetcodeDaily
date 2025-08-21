class Solution {
public:
    int firstOccurrence(vector<int> &nums, int target)
    {
        int first = -1;
        int left = 0;
        int right = size(nums) - 1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid]>=target)
            {
                if(nums[mid]==target) first = mid;
                right = mid - 1;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return first;
    }
    int lastOccurrence(vector<int> &nums, int target)
    {
        int last = -1;
        int left = 0;
        int right = size(nums) - 1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] <=target)
            {
                if(nums[mid]==target) last = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);
        if(first==-1) return {-1,-1};
        int last = lastOccurrence(nums, target);
        return {first, last};
    }
};
