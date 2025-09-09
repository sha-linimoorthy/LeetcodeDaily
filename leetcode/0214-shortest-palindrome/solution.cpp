class Solution {
public:
    string shortestPalindrome(string s) {
        long long prefix = 0, suffix = 0, base = 29, power = 1;
        int last_ind = -1;
        int mod = 1e9+7;

        for(int i=0; i<s.length(); i++)
        {
            int val = s[i] - '0' + 1;
            prefix = (prefix * base) % mod;
            prefix += val % mod;

            suffix = (suffix + val * power) % mod;
            power = (power * base) % mod;
            if(prefix == suffix) 
                last_ind = i;
        }

        string str = s.substr(last_ind+1);
        reverse(str.begin(), str.end());
        return str+s;
    }
};
