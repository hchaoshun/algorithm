//贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0, min_stock = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - min_stock);
            min_stock = min(min_stock, prices[i]);
        }
        return profit;
    }
};
