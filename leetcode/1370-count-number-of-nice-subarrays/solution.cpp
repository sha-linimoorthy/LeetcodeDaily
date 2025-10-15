class Solution {
public:
    int solve(vector<int>& nums, int k){
        int count = 0, r = 0, l = 0, c = 0;
        while(r<nums.size())
        {
            if(nums[r]%2==1) c++;
            while(c>k){
                if(nums[l]%2==1) c--;
                l++;
            }
            if(c<=k){
                count += (r-l+1);
            }
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};
