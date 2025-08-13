class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum;
        for(int i=0;i<size(nums);i++)
        {
            sum = 0;
            for(int j=i;j<size(nums);j++)
            {
                sum+=nums[j];
                if(sum==k) count++;
            }
        }

        return count;
        
    }
};


   
