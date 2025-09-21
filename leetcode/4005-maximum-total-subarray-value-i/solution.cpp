class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long result = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        result = (maxi -mini) * 1LL * k;
        return result;
    }
};
