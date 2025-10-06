class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int r = 0, l = 0;
        unordered_map<char,int> mp;
        while(r < s.size()){
            char ch = s[r];
            mp[ch]++;
            while(mp[ch]>1 && l<r){
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
    }
};
