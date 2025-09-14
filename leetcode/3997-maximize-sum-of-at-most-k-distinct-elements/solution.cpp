class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        for(int n:nums) {
            if (ans.size() < k && (ans.empty() || ans.back() != n)) {
                ans.emplace_back(n);
            }
        }
        return ans;
    }
};
