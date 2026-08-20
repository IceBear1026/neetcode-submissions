class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stack1;
        // loop through the array
        for(string token : tokens){
            // check the operators first
            if(token == "+"){
                int first_num = stoi(stack1.top());
                stack1.pop();
                int sec_num = stoi(stack1.top());
                stack1.pop();
                stack1.push(to_string(first_num + sec_num));
            } else if(token == "-"){
                int first_num = stoi(stack1.top());
                stack1.pop();
                int sec_num = stoi(stack1.top());
                stack1.pop();
                stack1.push(to_string(sec_num - first_num));
            } else if(token == "/"){
                int first_num = stoi(stack1.top());
                stack1.pop();
                int sec_num = stoi(stack1.top());
                stack1.pop();
                stack1.push(to_string(sec_num / first_num));
            } else if(token == "*"){
                int first_num = stoi(stack1.top());
                stack1.pop();
                int sec_num = stoi(stack1.top());
                stack1.pop();
                stack1.push(to_string(first_num * sec_num));
            } 
            
            // if it's not an operator, it would be numbers
            else {
                stack1.push(token);
            }
        }
        return stoi(stack1.top());
    }
};
