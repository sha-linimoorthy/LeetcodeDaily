class Solution {
public:
    int func(const vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int l = 0, r = 0, count = 0, sum = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            r++;
            count+=r-l;
        }
        return count;
  }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal-1);
    }
};
