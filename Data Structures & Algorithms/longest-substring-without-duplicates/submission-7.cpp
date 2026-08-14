class Solution {
public:
    // given a string s. Find the length of the longest substring without duplicate characters. 
    int lengthOfLongestSubstring(string s) {
        // this is a contiguous sequence of characters. Sliding windows might be the way to go. 
        int left = 0;
        int right = 0;
        set<char> unique_chars;

        // right index will be what keeps track of whether we should increase the substring or not. 
        int maxi = 0;
        while(right < s.size()){
            // IF it's a unique character of the current substring, then yes insert and increase the right index.
            if(!unique_chars.contains(s[right])){
                unique_chars.insert(s[right]);
                // after unique characters are all in there, we will check the size of that substring to see if it's larger than what we already had as our maximum length.
                maxi = max(maxi, (int)unique_chars.size());
                right++;
            } else {
            // so if the character is not unique we will remove it from the set and push the left side of the window. We will do it until we don't see the duplicate of what we find in the current index. For example: xyzxz. -> yzxz-> xz.
            unique_chars.erase(s[left]);
            left++;
            }
        }
        return maxi;
    }
};
