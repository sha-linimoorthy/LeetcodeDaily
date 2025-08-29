class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0; int end = 0;
        for(int i=0; i<s.size(); i++)
        {
            while(i < s.size() && s[i]==' ') i++; //skip spaces 
            if(i==s.size()) 
            {
                break;
            }
            while(i < s.size() && s[i]!=' ') //copy present to from first
            {
                s[end++] = s[i++];
            }
            reverse(s.begin() + start, s.begin() + end);
            s[end++] = ' '; ///add space after every word
            start = end;
        }
        s.resize(end - 1); //remove space for last
        return s;
    }
};
