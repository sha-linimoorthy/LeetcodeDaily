class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c=='('||c=='['||c=='{') st.push(c);
            else{
                if(st.empty()) return false;
                char cc = st.top();
                if(c==')'&&cc!='(' || c==']'&&cc!='[' || c=='}'&&cc!='{') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
