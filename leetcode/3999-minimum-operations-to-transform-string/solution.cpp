class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(), s.end());
        int bigi = 0;
        for(char c: s) {
            if(c!='a') {
                bigi = c - 'a';
                break;
            }
        }

        return abs(26 - bigi) % 26;
    }
};
