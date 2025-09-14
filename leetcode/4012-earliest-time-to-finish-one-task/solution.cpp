class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = INT_MAX;
        for(auto &i: tasks) {
            int s = i[0];
            int t = i[1];
            if(s+t<minTime) {
                minTime = s+t;
            }
        }
        return minTime;
    }
};
