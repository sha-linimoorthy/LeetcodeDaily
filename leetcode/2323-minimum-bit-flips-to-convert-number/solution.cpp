class Solution {
public:
    int countSetBits(int num){
        int c = 0;
        while(num!=0){
            c+=(num&1);
            num=num>>1;
        }
        return c;
    }
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        int count = countSetBits(num);
        return count;
    }
};
