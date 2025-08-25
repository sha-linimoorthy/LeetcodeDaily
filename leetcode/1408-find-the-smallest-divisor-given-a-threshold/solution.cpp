class Solution {
public:
    int findSum(const vector<int>& nums, int divisor)
    {
        int sum = 0;
        for(int j=0;j<nums.size();j++)
        {
            sum += (nums[j] + divisor - 1) / divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int answer = INT_MAX;
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while(left<=right)
        {
            int mid = (left + right) / 2;
            if(findSum(nums,mid)<=threshold)
            {
                answer = min(answer, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return answer;
    }
};
