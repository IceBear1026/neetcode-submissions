class Solution {
public:
    /*
    Only possibly collision that can happen between two numbers that are tangent to each other are:

    +   - 
    -> <-

    + + (same direction -> -> )
    - - (same direction <- <- )
    - + (goes away from each other <- ->)
    */

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack1;

        // loop through the current vector
        for(int asteroid : asteroids) {
            bool destroyed = false;
            // check collision and keep resolving the collision via while loop because there could be multiple collision that can happen.
            while(!stack1.empty() && stack1.top() > 0 && asteroid < 0){
                // if they are same value when in absolute, cancel out the current top() by pop().
                if(stack1.top() == abs(asteroid)){
                    stack1.pop();
                    destroyed = true;
                    break;
                }
                
                // if right(negative) is greater in absolutes, pop() the current top() and push the current asteroid element.
                else if(stack1.top() < abs(asteroid)){
                    stack1.pop();
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed){
                stack1.push(asteroid);
            }
        }

    // stack<int> has no begin()/end()
    // manual process
    vector<int> result;
    while(!stack1.empty()){
        result.push_back(stack1.top());
        stack1.pop();
    }
    reverse(result.begin(), result.end());

    return result;
    }
};