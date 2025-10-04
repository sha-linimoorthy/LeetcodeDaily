class Solution {
public:
    int mod = 1e9+7;
    void findNSI(vector<int>& arr, vector<int>& res){
        stack<int> st; int n = arr.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
    }
     void findPSI(vector<int>& arr, vector<int>& res){
        stack<int> st; int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSI_arr(n, n);
        vector<int> PSI_arr(n, -1);
        findNSI(arr, NSI_arr);
        findPSI(arr, PSI_arr);
        long long result = 0;
        for(int i=0; i<n; i++){
            int l = i - PSI_arr[i];
            int r = NSI_arr[i] - i;
            result = (result + (1LL * (l*r) * arr[i])%mod)%mod;
        }
        return result;
    }
};
