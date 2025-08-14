class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        int smaller_size,larger_size;
        for(int i=0;i<size(nums);i++)
        {
            if(nums[i]>pivot) 
            {
                larger.emplace_back(nums[i]);
            }
            else if(nums[i]<pivot)
            {
                smaller.emplace_back(nums[i]);
            }
        }
        smaller_size = size(smaller);
        larger_size = size(larger);
        for(int i=0;i<smaller_size;i++)
        {
            nums[i]=smaller[i];
        }

        for(int i=0;i<nums.size() - (larger_size+smaller_size);i++)
        {
            nums[smaller_size+i] = pivot;
        }

        for(int i=0;i<larger_size;i++)
        {
            nums[(nums.size()-larger_size)+i] = larger[i];
        }

        return nums;
        
    }
};
