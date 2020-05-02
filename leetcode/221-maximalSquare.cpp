//todo 状态转移方程： dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) ???
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result= 0;
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            result = max(result, dp[i][0]);
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            result = max(result, dp[0][j]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
    }
};
