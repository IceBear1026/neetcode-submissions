class MinStack {
// stack is a data structure that practices LIFO Last In First Out.
// Kind of like a bucket contrary to queue which is FIFO.  
private:
    stack<int> stacked; // regular stack 
    stack<int> min_stacked; // tracks minimums
public:
    MinStack() {

    }
    
    void push(int val) {
        stacked.push(val);
        if(min_stacked.empty()){
            min_stacked.push(val);
        } else {
            int current_min_top = min_stacked.top();
            min_stacked.push(min(val, current_min_top));
        }
    }
    
    void pop() {
        stacked.pop();
        min_stacked.pop();
    }
    
    int top() {
        return stacked.top();
    }
    
    int getMin() {
        return min_stacked.top();
    }
};
