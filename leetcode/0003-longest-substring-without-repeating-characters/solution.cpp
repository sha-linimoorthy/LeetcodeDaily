class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int r = 0, l = 0;
        vector<int> v(256, -1);
        while(r < s.size()){
            char ch = s[r];
            if(v[ch]!=-1){
                l = max(v[ch]+1, l);
            }
            v[ch] = r;
            r++;
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
};
