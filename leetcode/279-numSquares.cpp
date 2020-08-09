//类似与322零钱兑换问题
//dp[n] = min(dp[i], dp[i - j*j] + 1)
//i表示当前数字，j*j表示平方数
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (size_t i = 1; i <= n; ++i) {
            dp[i] = i;
        }
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
