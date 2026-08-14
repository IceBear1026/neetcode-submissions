class Solution {
public:
    int search(vector<int>& nums, int target) {
        // let's try binary search
        int head = 0;
        int tail = nums.size() - 1;
        int mid;
        while(head <= tail){
            mid = head + (tail - head) / 2;
            if(nums[mid] == target){
                return mid;
            }
            // example: [8,9,1,2,3,4,5,6,7]
            //                  m        t
            if(nums[head] > nums[mid]){
                // the right side is sorted.
                if(target >= nums[mid] && target <= nums[tail]){
                    head = mid + 1;
                }
                else{
                    tail = mid - 1;
                }

            }
            // example: [8,9,1,2,3,4,5,6,7]
            //          h       m        
            // left side is sorted.
            else if(target >= nums[head] && target <= nums[mid]){
                tail = mid - 1;
            }
            else {
                head = mid + 1;
            }
        }
        return -1;
    }





    /*
    Summary: The Train Concept with Examples

    The Break Point (The Train Analogy):
    Think of the original sorted array as one continuous ascending train:

    Original Train: [1→2→3→4→5→6→7→8→9→10]
    After rotation, the train gets cut and wrapped, but it's still ONE continuous train:

    Rotated Train:  [8→9→10] | [1→2→3→4→5→6→7]
                    (end)      (start wrapped around)
    The Check - nums[low] <= nums[mid]:

    If TRUE: No break between low and mid → left side is still on the same train (sorted)
    If FALSE: Break exists → right side is the sorted part of the train
    Real Example:

    nums = [8,9,10,1,2,3,4,5,6,7], target = 3

    Step 1: low=0 (8), mid=4 (2)
    8 <= 2? NO → break exists in left half
    Right half [2,3,4,5,6,7] IS the sorted train
    Is 3 in [2,7]? YES → search right
    */
};
