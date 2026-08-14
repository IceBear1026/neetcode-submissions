class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> unique_count;
        for(int i = 0; i < nums.size(); ++i) {
            unique_count[nums[i]]++;
        }

        vector<pair<int,int>> sort_array(unique_count.begin(), unique_count.end());
        sort(sort_array.begin(), sort_array.end(), [](auto& a, auto& b) {
            return a.second > b.second; // descending order;
        });

        vector<int> result;
        for(int j = 0; j < k; ++j) {
            result.push_back(sort_array[j].first);
        }
        return result;
    }
};
