class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0; 
        for(int num: nums){
            xorr ^= num;
        }
        int rightMostSet = (xorr&(xorr-1))^xorr;
        int b1 = 0, b2 = 0; 
        for(int num: nums){
            if(num&rightMostSet) b1 = b1 ^ num;
            else b2 = b2 ^ num;
        }
        vector<int> ans = {b1, b2};
        return ans;
    }
};
