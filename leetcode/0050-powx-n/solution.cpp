class Solution {
public:
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
        while(n > 0)
        {
            if (n%2==1) // Odd power 
            {
                answer *= x;
                n = n - 1;
            }
            else
            {
                x *= x;
                n /=2;
            }
        }
        if (power < 0) return (1.0 / answer);
        return answer;
        
    }
};
