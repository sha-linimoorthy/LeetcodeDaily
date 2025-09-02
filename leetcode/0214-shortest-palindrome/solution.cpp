class Solution {
public:
    vector<int> longestPrefixSuffix(string s)
    {
        int n = s.length();
        vector<int> lps(n,0);
        int prevLps = 0, i = 1;
        while(i<n)
        {
            if(s[prevLps]==s[i])
            {
                lps[i] = prevLps+1;
                prevLps++; i++;
            }
            else if(prevLps==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                prevLps = lps[prevLps - 1];
            }
            
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        string pattern = s;
        reverse(pattern.begin(), pattern.end());
        vector<int> lps = longestPrefixSuffix(s+"#"+pattern);
        int indx = lps.back();
        string str = s.substr(indx);
        reverse(str.begin(), str.end());
        return str+s;
    }
};
