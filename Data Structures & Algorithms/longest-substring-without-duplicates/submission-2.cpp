class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> unique_chars;
        int left = 0;
        int right = 0;
        int longest_length = 0;

        // while loop until the right hits the right most character within the string. 
        while(right < s.size()) {
            if(!unique_chars.contains(s[right])){
                unique_chars.insert(s[right]);
                longest_length = max((int)unique_chars.size(), longest_length);
                right++;
            } else {
                unique_chars.erase(s[left]);
                left++;
            }
            
        }
        return longest_length;
    }
};
