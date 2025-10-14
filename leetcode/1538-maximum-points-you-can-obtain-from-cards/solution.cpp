class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, rind = cardPoints.size() - 1;
        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }
        int maxSum = lsum;
        for(int i=k-1; i>=0; i--){
            rsum += cardPoints[rind--];
            lsum -= cardPoints[i];
            maxSum = max(maxSum, rsum + lsum);
        }
        return maxSum;
    }
};
