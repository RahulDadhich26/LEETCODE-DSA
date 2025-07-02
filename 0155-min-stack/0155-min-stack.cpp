class MinStack {
     stack<int> mainStack;  // Main stack to store all elements
    stack<int> minStack; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // Always push to main stack
        mainStack.push(val);
        
        // Push to min stack if it's empty or val is <= current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // Check if the element being popped is the current minimum
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();  // Remove from min stack too
            }
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
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