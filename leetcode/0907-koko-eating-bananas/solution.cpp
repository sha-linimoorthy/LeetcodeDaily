class Solution {
public:
    long long hoursNeeded(int speed, const vector<int> & piles)
    {
        long long total = 0;
        for(int i=0;i<piles.size();i++)
        {
            total += (piles[i] + speed - 1) / speed;
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left<=right)
        {
            int mid = left + ((right - left) / 2);
            if(hoursNeeded(mid,piles)<=h)
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
