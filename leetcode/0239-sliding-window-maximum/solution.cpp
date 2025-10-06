class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> ms;
        int l = 0, r = 0;
        while(r<nums.size()){
            ms.insert(nums[r]);
            
            if(r - l + 1 == k){
                ans.push_back(*ms.rbegin());
                ms.erase(ms.find(nums[l]));
                l++;
            }
            r++;
        }
        return ans;
    }
};
