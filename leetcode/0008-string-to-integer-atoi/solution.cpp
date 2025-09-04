class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0; 
        bool neg = false;
        int num=0;
        while(i<n && s[i]==' ') i++; //leading spaces

        if(i<n && s[i]=='+' || s[i]=='-')
        {
            neg = (s[i]=='-');
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<='9')
        {
            int digit = s[i] - '0';
            if(num > (INT_MAX - digit) / 10)
            {
                return neg ? INT_MIN: INT_MAX;
            }
            num = num *10 + digit;
            i++;
        }

        if(neg) return -(num);
        return num;
        
    }
};
