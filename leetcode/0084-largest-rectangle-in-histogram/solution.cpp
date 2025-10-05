class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int result = -1;
        int n = h.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && h[st.top()]> h[i]){
                int ele = h[st.top()];
                st.pop();
                int psi = st.empty()?-1:st.top();
                result = max(result, ele * (i - psi - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele = h[st.top()];
            st.pop();
            int psi = st.empty()?-1:st.top();
            result = max(result, ele * (n - psi - 1));
        }
        return result;
    }
};
