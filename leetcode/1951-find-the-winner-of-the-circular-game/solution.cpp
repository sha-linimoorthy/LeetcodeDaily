class Solution {
public:
    int solve(int indx, int k, vector<int>& a) {
        if(a.size()==1) return a[0];
        indx = (indx + k) % a.size();
        a.erase(a.begin()+ indx);
        return solve(indx, k, a);
    }
    int findTheWinner(int n, int k) {
        vector<int> a;
        for(int i=1;i<=n;i++) {
            a.push_back(i);
        }
        k--;
        return solve(0, k, a);
    }
};
