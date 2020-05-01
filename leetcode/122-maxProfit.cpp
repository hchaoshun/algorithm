//[7, 1, 5, 6] 第二天买入，第四天卖出，收益最大（6-1），所以一般人可能会想，怎么判断不是第三天就卖出了呢? 
//这里就把问题复杂化了，根据题目的意思，当天卖出以后，当天还可以买入，
//所以其实可以第三天卖出，第三天买入，第四天又卖出（（5-1）+ （6-5） === 6 - 1）。
//所以算法可以直接简化为只要今天比昨天大，就卖出。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) sum += diff;
        }
        return sum;
    }
};
