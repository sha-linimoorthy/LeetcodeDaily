class Solution {
public:
    void swap(vector<int>& arr,int first, int second)
    {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i] != i+1)
            {
                if(nums[i]==nums[nums[i]-1]) return nums[i];
                else swap(nums, i, nums[i]-1);
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};
