class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> scores;

        for(string op : operations) {
            if(op == "+"){
                string last_one = scores.top();
                scores.pop();

                string last_two = scores.top();
                int final_sum_to_add = stoi(last_one) + stoi(last_two);
                
                scores.push(last_one);
                scores.push(to_string(final_sum_to_add));
            }
            else if(op == "C"){
                scores.pop();
            }
            else if(op == "D") {
                int doubled_num = 2 * stoi(scores.top());
                scores.push(to_string(doubled_num));
            }
            // do an else after checking "+" and "D" and "C" we will add it to the stack because it's an integer. 
            else {
                scores.push(op);
            }
        }
        int count = 0;
        while(!scores.empty()){
            count += stoi(scores.top());
            scores.pop();
        }
        return count;
    }
};