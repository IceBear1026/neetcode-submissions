class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we keep track of the largest difference until we complete the looping of the vectors. 
        int largest_difference = 0;
        for (int i = 0; i < prices.size(); ++i){
            for ( int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] - prices[i] > largest_difference){
                    largest_difference = prices[j] - prices[i];
                } 
            }
        }
        return largest_difference;
    }
};
