class MyStack {
// stacks are LIFO - last in first out.
// use two queues.
// 
private:
    stack<int> stack1;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);    
    }
    
    int pop() {
        int value = stack1.top();
        stack1.pop();
        return value;
    }
    
    int top() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */