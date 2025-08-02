class Solution {
public:
    void swap(vector<int> &arr, int first, int second)
    {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    } 
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        int n= nums.size();
        vector<int> dupeNums;
        while(i<n)
        {
            if(nums[i] != i+1)
            {
                if(nums[i]==nums[nums[i]-1])
                {
                    i++;
                }
                else
                {
                    swap(nums, i, nums[i]-1);
                }

            }
            else
            {
                i++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1 && nums[i<i])
            {
                dupeNums.emplace_back(nums[i]);
            }
        }
        return dupeNums;
    }
};
