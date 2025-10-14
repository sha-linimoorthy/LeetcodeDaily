class Solution {
public:
    int numberOfSubstrings(string s) {
        int maxCount = 0;
        int n = s.size();
        vector<int> lastSeen(3,-1);
        for(int i=0; i<n; i++){
           lastSeen[s[i]-'a'] = i;
           maxCount += min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
        }
        return maxCount;
    }
};
