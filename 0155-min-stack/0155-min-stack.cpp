class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else {
            if(val >= mini) st.push(val);
            else {
                st.push(2*val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long n = st.top();
        st.pop();
        if(n < mini) mini = 2 * mini - n;
    }
    
    int top() {
        if(st.empty()) return -1;
        long long n = st.top();
        if(n < mini) {
            return mini;
        }
        return n;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */