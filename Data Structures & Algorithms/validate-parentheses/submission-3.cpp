class Solution {
public:
    bool isValid(string s) {
        stack<char> stacked_char;
        for (int i = 0; i < s.length(); ++i) {
            // stack up any correseponding left side brackets.
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stacked_char.push(s[i]);
            }
            // if it's not any of the other left side characters they will be the right side ones. 
            else {
                // make sure we caught anything. If we didn't catch anything return false. 
                if(stacked_char.empty()){
                    return false;
                }
                // this will have LIFO order which will keep with the corresponding right side brackets to pair up with left brackets in reverse order. 
                char current_most_recent = stacked_char.top();
                if(s[i] == ')' && current_most_recent == '(') {
                    stacked_char.pop();
                }
                else if(s[i] == ']' && current_most_recent == '[') {
                    stacked_char.pop();
                }
                else if(s[i] == '}' && current_most_recent == '{') {
                    stacked_char.pop();
                }
                else {
                    // meaning other characters exist other than these 6 options. 
                    return false;
                }
            }
        }
        return stacked_char.empty();
    }
};
