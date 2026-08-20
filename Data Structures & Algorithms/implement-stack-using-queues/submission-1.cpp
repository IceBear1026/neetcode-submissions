class MyStack {
// using queues
// queue<int> q;

// q.push(10);

// q.front();
// q.end();

// removing an element from the front
// q.pop();
private:
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        // so first add the value into the queue.
        q.push(x);

        // we get the size of the queue to do a loop over it.
        int n = q.size();

        // the loop
        for (int i = 0; i < n - 1; ++i) {
            // we are pushing the value of the front back into the queue I believe.
            q.push(q.front());

            // that same instance of the one where we copied the front value to the back is being removed.
            q.pop();
        }

        /*
        so let's say we have [1, 2, 3]

        let's say we are trying to add the number 7. 

        q.push(7);

        [1,2,3,7]
        loop over this queue
        
        // q.push(q.front());
        [1,2,3,7,1]
        
        // q.pop();
        [2,3,7,1]

        and because we are doing a loop over n - 1, we will preserve the value we added, meaning for this array we will only loop 3 times so that 7 is in the front. 

        // loop three times 
        [7,1,2,3]

        and now we have a queue that will always have most recently pushed value in the q.front() in which we can now use q.pop() (queue function) to remove it and although it's reversed we can use it like stack.
        */

    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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