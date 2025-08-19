class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int cont_count = 0;

        for(int i = 0;i < size(nums); i++)
        {
            if(nums[i]==0)
            {
                cont_count++;
                count+= cont_count;
            }
            else
            {
                cont_count = 0;
            }
        }

        return count;
        
    }
};
