class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = -1, r = 0, l = 0, maxCount = 0;
        unordered_map<char, int> mp;

        while(r<s.length()) {
            mp[s[r]]++;
            maxCount = max(maxCount, mp[s[r]]);
            r++;
            if(r-l-maxCount > k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};
