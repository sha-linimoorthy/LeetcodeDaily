class Solution {
public:
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
    void findNGI(vector<int>& arr, vector<int>& res){
        stack<int> st; int n = arr.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
    }
     void findPGI(vector<int>& arr, vector<int>& res){
        stack<int> st; int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSI_arr(n, n);
        vector<int> NGI_arr(n, n);
        vector<int> PSI_arr(n, -1);
        vector<int> PGI_arr(n, -1);
        findNSI(nums, NSI_arr);
        findNGI(nums, NGI_arr);
        findPSI(nums, PSI_arr);
        findPGI(nums, PGI_arr);
        long long smallest = 0, largest = 0, lg, ls, rg, rs; 
        for(int i=0; i<n; i++){
            lg = i - PGI_arr[i];
            ls = i - PSI_arr[i];
            rg = NGI_arr[i] - i; 
            rs = NSI_arr[i] - i;
            smallest = smallest + (ls * rs * nums[i]);
            largest = largest + (lg * rg * nums[i]);
        }
        return largest - smallest;
    }
};
