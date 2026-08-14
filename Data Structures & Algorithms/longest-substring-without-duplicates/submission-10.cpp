class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // without any duplicates so I'm thinking of using set. 
        // this sounds like a sliding windows problem. 
        
        // these will be my indexes 
        int left = 0;
        int right = 0;
        unordered_set<char> uniq_container;

        // we also need the maximum counter
        int substring_check = 0;
        // right will increment as the windows gets larger. 
        while(right < s.length()){
            if(!uniq_container.contains(s[right])){
                uniq_container.insert(s[right]);
                right++;
                int length = right - left;
                substring_check = max(length, substring_check);
                continue;
            }
            // now the set has unique characters. 
            // and also the right is incremented to next loop.

            // if we do see the same one...
            if(uniq_container.contains(s[right])){
                int length = right - left;
                // before we remove it get the length.
                substring_check = max(length, substring_check);
                // remove the left as we just found a duplicate.
                uniq_container.erase(s[left]);
                left++;
            }
        }
        return substring_check;
    }
};
