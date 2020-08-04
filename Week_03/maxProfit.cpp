class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            if(prices[i + 1] > prices[i]){
                maxValue += prices[i + 1] - prices[i];
            }
        }
        return maxValue;
    }
};