class Solution {
public:
    // compare the numbers and stop the loop when two elements equal the target. 
    vector<int> twoSum(vector<int>& nums, int target) {
        int num_length = nums.size();
        for (int i = 0; i < num_length; ++i){
            for (int j = i + 1; j < num_length; ++j) {
                if(nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
    }
};
