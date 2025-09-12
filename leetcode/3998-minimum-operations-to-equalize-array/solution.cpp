class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool isSame = true;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]!=nums[i-1]) isSame = false;
        }

        return isSame ? 0 : 1;
    }
};
