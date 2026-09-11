class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> uniqueValues(nums.begin(), nums.end());
        vector<int> new_result(uniqueValues.begin(), uniqueValues.end());

        for (int i = 0; i < new_result.size(); i++) {
            nums[i] = new_result[i];
        }

        return new_result.size();
    }
};