class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int maxi = 0;
        int kcopy = k;
        while(r < nums.size()){
            if(nums[r]==0) {
                if(kcopy==0) continue;
                else if(k==0){
                    while(l<r && nums[l]==1) l++;
                    l++;
                }
                else {
                    k--;
                }
            }
            r++;
            maxi = max(maxi, r-l); 
        }
        maxi = max(maxi, r-l);
        return maxi;
    }
};
