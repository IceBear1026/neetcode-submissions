class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a temporary key amongst anagrams and use that to store other anagrams inside. 
        map<string, vector<string>> key_map;
        for (int i = 0; i < strs.size(); ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            // creates/references the key and add to the vector that references that key. 
            key_map[s].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto& [key , value] : key_map){
            result.push_back(value);
        }

        return result;
    }
};
