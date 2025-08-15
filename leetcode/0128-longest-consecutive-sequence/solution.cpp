class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        int curr_count=0;
        int max_count=0;
        for(int i=0;i<size(nums);i++){
            nums_set.insert(nums[i]);
        }

        for(auto &it: nums_set)
        {
            int x = it;
            curr_count = 0;
            if(nums_set.find(x-1)==nums_set.end())
            {
                curr_count++;
                x+=1;
                while(nums_set.find(x)!=nums_set.end())
                {
                    x += 1;
                    curr_count++;
                }
                
            }

            max_count = max(curr_count,max_count);
        }

        return max_count;
    }
};
