class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we are going to do a binary search
        int head = 0;
        int tail = nums.size() - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2; 
            if(target == nums[mid]) {
                return mid;
            }
            
            if(target > nums[mid]){
                head = mid + 1;
            }
            else if(target < nums[mid]){
                tail = mid - 1;
            }
        }
        return -1;
    }
};
