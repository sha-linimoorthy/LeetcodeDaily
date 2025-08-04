class Solution {
public:
    void swap(vector<int> &nums, int first, int second)
    {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int size = nums.size();
        while(i<size)
        {
            if(nums[i]>0 && nums[i]<=size && nums[i]!=nums[nums[i]-1])
            {
                swap(nums, i,nums[i]-1);
            }
            else
            {
                i++;
            }
        }
        for(int i=0;i<size;i++)
        {
            if(nums[i]!=i+1) return i+1;
        }
        return size+1;
    }
};
