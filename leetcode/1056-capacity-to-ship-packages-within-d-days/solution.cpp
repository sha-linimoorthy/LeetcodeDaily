class Solution {
public:
    int summationWeights(const vector<int> &weights)
    {
        int sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
        }
        return sum;
    }
    int shippingDays(const vector<int> &weights, int capacity)
    {
        int days = 1;
        int loads = 0;

        for(int i=0;i<weights.size();i++)
        {
            if(loads + weights[i] > capacity)
            {
                days++;
                loads = weights[i];
            }
            else
            {
                loads += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = summationWeights(weights);
        while(left<=right)
        {
            int mid = (left + right) / 2;
            if(shippingDays(weights, mid) <= days)
            {
                right = mid - 1;
            }
            else
            {
               left = mid + 1;
            }
        }        
        return left;
    }
};
