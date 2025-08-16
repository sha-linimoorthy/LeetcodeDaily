class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int element1 = 0, element2 = 0;
        int countelement1 =0, countelement2 =0, min_count = size(nums) /3;
        vector<int> result;
        for(int i=0;i<size(nums);i++)
        {
            if(count1==0 && element2!=nums[i])
            {
                count1++;
                element1 = nums[i];
            }

            else if(count2 == 0 && element1!=nums[i])
            {
                count2++;
                element2 = nums[i];
            }

            else if(nums[i]==element1) count1++;

            else if(nums[i]==element2) count2++;

            else
            {
                count1--;
                count2--;
            }

        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element1) countelement1++;
            else if(nums[i]==element2) countelement2++;
        }
        if(countelement1>min_count) result.emplace_back(element1);
        if(countelement2>min_count) result.emplace_back(element2);
        return result;
    }
};
