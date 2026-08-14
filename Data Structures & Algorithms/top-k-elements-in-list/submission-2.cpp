class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // this will create key value storage for the integers inside nums.
        map<int, int> unique_freq;

        for(int i = 0; i < nums.size(); ++i){
            unique_freq[nums[i]]++;
        }

        // the reason why we need to create this is because vector is able to use sort for ascending and descending values.
        vector<pair<int, int>> vect;

        for(auto& [key, value] : unique_freq){
            vect.push_back({key,value});
        }

        // so after storing it into the pair I can sort it via the second value of the pair by referencing .second. 
        sort(vect.begin(), vect.end(), [] (auto& a, auto& b) { return a.second > b.second; });

        vector<int> result;
        for(int j = 0; j < k; ++j) {
            result.push_back(vect[j].first);
        }

        return result;
    }
};
