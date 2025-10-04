class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        string result = "";
        for(char currVal:num) {
            while(k && !st.empty() && st.back() > currVal) {
                k--;
                st.pop_back();
            }
            st.push_back(currVal);
        }
        while(k && !st.empty()) {
            k--;
            st.pop_back();
        }
        int i =0;
        while(i<st.size() && st[i]=='0') i++;
        result = (i==st.size()) ? "0" : st.substr(i);
        return result;
    }
};
