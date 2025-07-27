class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        if(x==INT_MAX || x==INT_MIN) return 0;
        while(x!=0)
        {
            if(revNum > INT_MAX / 10 || revNum < INT_MIN /10) return 0;
            revNum = 10*revNum + x%10;
            x = x/10;
        }
        return revNum;
    }
};
