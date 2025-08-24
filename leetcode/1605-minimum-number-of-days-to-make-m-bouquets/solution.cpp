class Solution {
public:
    int totalBouquets(const vector<int> &bloomDay, int day, int k)
    {
        int count = 0;
        int bouquets = 0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=day) count++;
                else count = 0;

                if(count==k)
                {
                    bouquets++;
                    count = 0;
                }
            }
        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((1LL*m*k) > n) return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while(left<=right)
        {
            int mid = left + ((right - left) / 2);
            if(totalBouquets(bloomDay, mid, k)>=m) 
            {
                answer = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
    
        return answer;
    }
};
