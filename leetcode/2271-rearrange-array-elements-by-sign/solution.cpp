class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        int posIndx=0;
        int negIndx=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                result[posIndx] = nums[i];
                posIndx +=2;
            }
            else
            {
                result[negIndx] = nums[i];
                negIndx +=2;
            }
        }

        return result;
        
    }
};
