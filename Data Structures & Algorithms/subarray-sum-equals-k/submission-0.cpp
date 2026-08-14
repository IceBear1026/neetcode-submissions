class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // this is another window sliding problem. 
        int count = 0;
        for ( int i = 0; i < nums.size(); ++i) {
            // every different scenario of that number will exist on each of the index.
            // That's why we need to create a new sum every time on each index. 
            int sum = 0; 
            for ( int j = i; j < nums.size(); ++j) {
                sum+= nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};