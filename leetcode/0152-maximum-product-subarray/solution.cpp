class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double max_prod = 0;
        int n = size(nums);
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            double prod = 1;
            for(int j=i;j<n;j++)
            {
                prod *= nums[j];
                if(prod>max_prod)
                {
                    max_prod = prod;
                }
            }
        }

        return (int) max_prod;
        
    }
};
