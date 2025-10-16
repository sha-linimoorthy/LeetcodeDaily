class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), l = 0, r = 0;
        int startIndx = -1, minLen = INT_MAX, count = 0;
        vector<int> mp(256, 0);
        for(char c: t){
            mp[c]++;
        }
        while(r < m){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;
            while(count==n){
                if(r - l + 1 < minLen) {
                    minLen = min(minLen, r - l + 1);
                    startIndx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++; 
            }
            r++;
        }
        return startIndx==-1 ? "" : s.substr(startIndx, minLen);
    }
};
