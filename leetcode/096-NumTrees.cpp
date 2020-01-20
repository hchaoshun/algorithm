//Catalan数，转换为dp问题
class Solution {
public:
    //f(0) = 1, f(1) = 1;
    //f(2) = f(0)*f(1) + f(1)*f(0)
    //f(3) = f(0)*f(2) + f(1)*f(1) + f(2)*f(0)
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
