class Solution {
public:
    // stack LIFO = Last In First Out
    // stack<int> st;
    // st.push(10);
    // st.top() // for the reading the value
    // st.pop();
    bool isValid(string s) {
        stack<char> stacked_chars; 
        for(char c : s) {
            // so stack up specific characters
            if (c == '(' || c == '{' || c == '[')  {
                stacked_chars.push(c);
                continue;
            }
            if (stacked_chars.empty()) {
                return false;
            }
            char top_recent_bracket = stacked_chars.top();
            if (c == ')' && top_recent_bracket == '(') {
                stacked_chars.pop();
            }
            else if (c == '}' && top_recent_bracket == '{') {
                stacked_chars.pop();
            }
            else if (c == ']' && top_recent_bracket == '[') {
                stacked_chars.pop();
            }
            else {
                return false;
            }
        }
        return stacked_chars.empty();
    }
};
