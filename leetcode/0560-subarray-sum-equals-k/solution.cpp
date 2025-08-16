class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum_freq;
        int presum = 0;
        int count = 0;
        presum_freq[presum]++;
        for(int i=0;i<size(nums);i++)
        {
            presum += nums[i];
            if(presum_freq.find(presum - k) != presum_freq.end())
            {
                count += presum_freq[(presum-k)];
            }
            presum_freq[presum]++;
        }

        return count;
        
    }
};
