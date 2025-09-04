class Solution {
public:
    string intToRoman(int num) {
         vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
         vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
         string result = "";
         for(int i=0; i<13; ++i)
         {
            int v = value[i];
            string s = symbol[i];
            while(num>=v)
            {
                result+=s;
                num -= v;
            }
         }

        return result;
    }
};
