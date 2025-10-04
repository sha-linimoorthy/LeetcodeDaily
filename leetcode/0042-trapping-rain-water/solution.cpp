class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0; int n = height.size();
        vector<int>sufixMax(n,0); sufixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            sufixMax[i] = max(sufixMax[i+1], height[i]);
        }

        int preMax = height[0];
        for(int i=0; i<n; i++){
            preMax = max(preMax, height[i]);
            total += min(sufixMax[i], preMax) - height[i];
        }

        return total;
    }
};
