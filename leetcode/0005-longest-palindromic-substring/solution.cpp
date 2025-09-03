class Solution {
public:
    string findPali(int l, int r, int& maxLen, string &maxStr, string s)
    {
         while(l>=0 && r<s.length() && s[l]==s[r])
            {
                if((r - l + 1) > maxLen)
                {
                    maxStr = s.substr(l,r - l + 1);
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        return maxStr;
    }
    string longestPalindrome(string s) {
        string maxStr="";
        int maxLen = 0;
        for(int i=0; i<s.length(); i++)
        {
            //Odd length
            findPali(i,i,maxLen,maxStr,s);
            //Even length
            findPali(i,i+1,maxLen,maxStr,s);
     
        }
        return maxStr;
    }
};
