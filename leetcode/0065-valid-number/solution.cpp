class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        int countDot = 0, countExp = 0;
        bool digitBefExp = false, digitAftExp = true; // assume true unless exponent exists

        for (int i = 0; i < len; i++) {
            char c = s[i];

            if (isdigit(c)) {
                if (countExp)
                    digitAftExp = true;
                else
                    digitBefExp = true;
            }
            else if (c == '.') {
                if (countDot || countExp) return false; // only one dot and not after 'e'
                countDot++;
            }
            else if (c == 'e' || c == 'E') {
                if (countExp || !digitBefExp || i == len - 1) return false;
                countExp++;
                digitAftExp = false; // must reset, digit after e must be found
            }
            else if (c == '+' || c == '-') {
                // must be at beginning or after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false; // invalid character
            }
        }

        // must have at least one digit before e, and if e exists, a digit after
        return digitBefExp && digitAftExp;
    }
};

