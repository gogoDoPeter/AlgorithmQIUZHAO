class MinStack {
    stack<int> mStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        mStack.push(x);
        minStack.push(min(x, minStack.top()));
    }
    
    void pop() {
        mStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */