class Solution {
public:
    int possibleSplit(const vector<int> nums, int maxSum)
    {
        int sub_array = 1, array_sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(array_sum + nums[i] <= maxSum)
            {
                array_sum += nums[i];
            }
            else
            {
                sub_array ++;
                array_sum = nums[i];
            }
        }
        return sub_array;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        while(start<=end)
        {
            int mid = (start+end)/ 2;
            if(possibleSplit(nums, mid)<=k)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};
