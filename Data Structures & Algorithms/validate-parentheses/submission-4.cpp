class Solution {
public:
// given a string with only these 6 characters. 
    bool isValid(string s) {
        // use stack 
        stack<char> stacked_chars;
        for ( char c : s ) {
            // stack up the left side of the brackets into the stack as it will contain the reverse order (LIFO) of the characters to verify the other half of the string.
            if (c == '(' || c == '{' || c == '['){
                stacked_chars.push(c);
            }
            else if(stacked_chars.empty()){
                return false;
            }
            // since there are only 3 other characters:
            else {
                char curr_stack_top = stacked_chars.top();
                if ( c == ')' && curr_stack_top == '(') {
                    stacked_chars.pop();
                }
                else if ( c == '}' && curr_stack_top == '{') {
                    stacked_chars.pop();
                }
                else if ( c == ']' && curr_stack_top == '[') {
                    stacked_chars.pop();
                }
                else {
                    // since it didn't meet the 6 characters. 
                    return false;
                }
            }
        }
        return stacked_chars.empty();
    }
};
