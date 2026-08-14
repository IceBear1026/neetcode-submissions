class Solution {
public:
    bool isValid(string s) {
        // you are given only three different types of strings.
        // we are checking its pairs from left to right but they will have to be in a reverse order. 
        // use stack because we can check from the most left to right. 
        stack<char> storage;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                storage.push(s[i]);
                continue;
            }
            // now the left side of the string is filled.
            if(storage.empty()){
                return false;
            }
            char top_of_stack = storage.top();
            if (top_of_stack == '(' && s[i] == ')'){
                storage.pop();
                continue;
            }
            else if(top_of_stack == '{' && s[i] == '}'){
                storage.pop();
                continue;
            }
            else if(top_of_stack == '[' && s[i] == ']'){
                storage.pop();
                continue;
            }
            else {
                return false;
            }
        }
        return storage.empty();
    }
};
