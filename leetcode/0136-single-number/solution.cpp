class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<size(nums);i++)
        {
            result = result ^ nums[i];
        }
        return result;
        
    }
};
