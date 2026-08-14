class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // so per integers we are getting a COUNT of however many times we see it and we are going to loop over that and limit that up to integer k. 
        map<int, int> uniq_int_count;
        for (int i = 0; i < nums.size(); ++i){
            // use that number per index as unique value and count.
            uniq_int_count[nums[i]]++;
        }

        // store in different container
        vector<pair<int, int>> result;
        for (auto& [key, value] : uniq_int_count) {
            result.push_back({key, value});
        }
        // another way of doing this is:
        // vector<pair<int, int>> result(uniq_int_count.begin(), unique_int_count.end());

        // sort 
        // lambda to make it descending
        sort(result.begin(), result.end(), [](auto& a, auto& b) { return a.second > b.second; });

        vector<int> final_result;
        for (int j = 0; j < k; ++j){
            final_result.push_back(result[j].first);
        }
        return final_result;
    }
};
