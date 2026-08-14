class Solution {
public:
    bool isValid(string s) {
        // Last In, First Out (LIFO)
        stack<char> brackets;

        for (char c : s) {
            // looping through the entire string in order of where these brackets live. Hence when we push into stack it will keep the reversed order. 
            if(c == '(' || c == '{' || c == '[' ) {
                brackets.push(c);
            } else {
                // else basically allows us to loop along with checking the brackets and verify after being put into the stack, if the other pair of that brackets exist in the string in the same reversed order. 
                if(brackets.empty()){
                    return false;
                }
                // this will return the LIFO bracket.
                char mostRecentOpening = brackets.top();

                if(c == ')' && mostRecentOpening == '(') {
                    // remove the top most bracket since it passed.
                    brackets.pop();
                }
                else if (c == '}' && mostRecentOpening == '{') {
                    brackets.pop();
                }
                else if (c == ']' && mostRecentOpening == '[') {
                    brackets.pop();
                } else { 
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};
