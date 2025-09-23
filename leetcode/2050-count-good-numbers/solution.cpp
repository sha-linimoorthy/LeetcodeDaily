class Solution {
public:
    long mod = 1e9+7;
    long powerFunc(long x, long a){
        long ans = 1;
        while(a) {
            if(a%2==0) {
                x = (x*x) % mod;
                a = a/2;
            }
            else{
                ans = (ans * x) % mod;
                a = a - 1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long even = (n+1) / 2;
        long odd = n/2;
        return (int) ((powerFunc(5,even) * powerFunc(4, odd)) % mod);
    }
};
