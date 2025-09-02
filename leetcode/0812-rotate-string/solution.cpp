class Solution {
public:
    bool kmp(string str, string pat, vector<int> lps)
    {
        int i=0, j=0;
        while(i<str.length())
        {
            if(str[i]==pat[j]) 
            {
                i++;j++;
            }
            else
            {
                if(j==0) i++;
                else j = lps[j-1];
                
            }
            if(j==pat.length()) return true;
        }
        return false;
    }
    vector<int> longestPrefixSuffix(string pattern)
    {
        int len = pattern.length();
        vector<int> lps(len, 0);
        int prevLps=0, i=1;
        while(i<len)
        {
            if(pattern[i]==pattern[prevLps])
            {
                lps[i] = prevLps+1;
                prevLps++; 
                i++;
            }
            else if(prevLps==0)
            {
                lps[i] =0;
                i++;
            }
            else prevLps = lps[prevLps - 1];
        }
        return lps;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        vector<int> lps = longestPrefixSuffix(goal);
        return kmp(s+s,goal,lps);
    }
};
