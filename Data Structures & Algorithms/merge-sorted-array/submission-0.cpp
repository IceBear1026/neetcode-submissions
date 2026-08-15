class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vect;
        for(int i = 0; i < m; ++i){
            vect.push_back(nums1[i]);
        }
        for(int j = 0; j < n; ++j){
            vect.push_back(nums2[j]);
        }
        sort(vect.begin(), vect.end());
        nums1 = vect;
    }
};