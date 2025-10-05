class Solution {
public:
    int findLargestRec(vector<int>& m){
        stack<int> st;
        int maxi = -1, n = m.size(), ele;
        for(int i=0; i<n; i++){
            ele = m[i];
            while(!st.empty() && m[st.top()]>=ele){
                int curr = st.top();
                st.pop();
                int prevSml = st.empty()?-1:st.top();
                maxi = max(maxi, m[curr]*(i - prevSml - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            int prevSml = st.empty()?-1:st.top();
            maxi = max(maxi, m[curr] * (n - prevSml - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int maxi = -1;
        vector<vector<int>> mat(r, vector<int>(c, 0));
        for(int i=0; i<c; i++){
            int c = 0;
            for(int j=0; j<r; j++){
                if(matrix[j][i]=='1'){
                    c++;
                    mat[j][i] = c;
                }
                else c = 0;
            }
        }

        for(int i=0; i<r; i++){
            maxi = max(maxi, findLargestRec(mat[i]));
        }

        return maxi;
    }
};
