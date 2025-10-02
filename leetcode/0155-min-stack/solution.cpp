class MinStack {
public:
    stack<long long> st; 
    long long mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else{
            if(val<mini) {
                st.push(2LL*val-mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        st.pop();
        if(x<mini) {
            mini = 2*mini - x;
        }
    }
    
    int top() {
        long long x = st.top();
        if(x<mini) return mini;
        return x;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
