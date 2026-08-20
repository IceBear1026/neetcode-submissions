class MyQueue {

private:
    stack<int> stack1;
public:
    MyQueue() {}
    // pushes element x to the back of the queue
    void push(int x) {
        // think TOWER OF HANOI
        stack<int> stack2;

        // reverse existing elements
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }

        // push new element
        stack1.push(x);

        // reverse back
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    // removes the element from the front of the queue and returns it
    int pop() {
        int val = stack1.top();
        stack1.pop();
        return val;
    }
    
    // returns the element at the front of the queue
    int peek() {
        return stack1.top();
    }
    
    // returns true if the queue is empty
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */