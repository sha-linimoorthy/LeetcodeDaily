class Solution {
public:
    string preProcess(string &s)
    {
        string str = "#";
        for(char c: s)
        {
            str += c;
            str += "#";
        }
        return str;
    }
    string longestPalindrome(string s) {
        string str = preProcess(s);
        int c = 0, r = 0, l = 0;
        int n = str.length();
        vector<int> p(n, 0);
        for(int i=0; i<n; i++)
        {
            if(i < c+p[c]) //part of prev palindrome
                p[i] = min(c+p[c]-i, p[2*c-i]); // min of right(inside boundry) or mirror 
            l = i-p[i]-1;
            r = i+p[i]+1;
            while(l>=0 && r<n && str[l]==str[r])
            {
                p[i]++;
                l--;
                r++;
            }
            if(p[c]< p[i]) //find longest center pali
                c=i;
        }
        int max_len = INT_MIN, indx = 0;
        for(int i=0; i<p.size(); i++)
        {
            if(p[i] > max_len)
            {
                max_len = p[i];
                indx = i;
            }
            cout << p[i];
        }
        int start = (indx - max_len) / 2;
        return s.substr(start, max_len);
        
    }
};
