class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;
        bool sign = true;
        if(dividend<0 && divisor>0)sign = false;
        else if(dividend>0 && divisor<0) sign = false;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long ans = 0, count;

        while(n>=d){
            count = 0;
            while(n >= (d<<(count+1))){
                count++;
            }
            n = n - (d<<count);
            ans += (1<<count);
        }
        if(ans==(1<<31) && sign) return INT_MAX;
        else if(ans==1<<31 && !sign) return INT_MIN;
        return sign?ans:-ans;
    }
};
