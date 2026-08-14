class Solution {
public:
    bool isAnagram(string s, string t) {
        // create a hash map that has unique key and value as the amount of characters that are repeated from string and check boolean if they equal the same. 
        map<char, int> s_map;
        map<char, int> t_map; 
        for (int i = 0; i < s.length(); ++i){
            // adds that specific character as a unique key and count the amount of times it appears in the string.
            s_map[s[i]]++;
        }

        for (int j = 0; j < t.length(); ++j) {
            // do the same for string t
            t_map[t[j]]++;
        }
        return s_map == t_map;
    }
};
