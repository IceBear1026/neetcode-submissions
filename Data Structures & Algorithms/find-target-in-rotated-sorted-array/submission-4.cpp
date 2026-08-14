class Solution {
public:
    int search(vector<int>& nums, int target) {
        // start off with two different indexes to check the left and right side of the array. 
        // we will verify if it's sorted within the sorted range. 
        // we will update the head and tail of the indexes per loop with head = mid + 1 or tail = mid -1 and etc
        // the mid is calculated every loop as int mid = start + (tail - head) / 2

        int head = 0;
        int tail = nums.size() - 1;

        int mid; 

        // the reason why while loop is this is because as long as head is lower than tail, there are still ranges of numbers to go through within the vector.
        while(head <= tail) {
            mid = head + (tail - head)/2;

            if(nums[mid] == target){
                return mid;
            }

            // example: [8,9,1,2,3,4,5,6,7]
            if(nums[head] > nums[mid]){
                // this means right side is sorted. we need to now check the target.
                if(nums[mid] <= target && nums[tail] >= target){
                    head = mid + 1;
                }
                else {
                    tail = mid - 1;
                }
            }
            else {
                if(nums[head] <= target && nums[mid] >= target){
                    tail = mid - 1;
                }
                else {
                    head = mid + 1;
                }
            }

        }
        return -1;
    }
};
