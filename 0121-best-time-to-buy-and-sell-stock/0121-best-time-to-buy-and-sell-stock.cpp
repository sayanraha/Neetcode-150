class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int minBuy = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minBuy = min(minBuy, price);
            maxProfit = max(maxProfit, price - minBuy);
        }

        return maxProfit;
    }
};