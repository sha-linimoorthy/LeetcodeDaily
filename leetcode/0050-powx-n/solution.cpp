class Solution {
public:
    double powerFun(double x, int n, double ans){
        if(n==0) return ans;
        if((n&1)==0) { x = x*x; n = n/2; }
        else {ans*=x; n = n -1; }
        return powerFun(x,n,ans);
    }
    double myPow(double x, int n) {
        int power = n;
        double answer = 1;
        if (n==INT_MAX || n==INT_MIN)
        {
            if(x==1) return x;
            else if(x==-1)
            {
                if(n==INT_MIN) return 1;
                return x;
            }

            else return 0;
        }
        if (n < 0) n = n * -1;
        answer = powerFun(x, n, 1.0);
        return (power<0)?(1/answer):answer;        
    }
};
