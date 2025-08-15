class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&
                (n & (n-1)) == 0 &&                // check if its power of 2 
                (n & 0x55555555) != 0;                // Check if it has 1 inodd position
    }
};
