class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        if (n <= 1) return 0;
        vector<int> dp(n, 0);
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                dp[i] = 0;
                continue;
            }
            if (s[i-1] == '(' && i - 2 >= 0) {
                dp[i] = dp[i-2] + 2;
            } else {
                int max_pos = i - dp[i-1] - 1;
                if (max_pos >= 0 && s[max_pos] == '(') {
                    int before_res = 0;
                    if (max_pos - 1 >= 0) {
                        before_res = dp[max_pos - 1];
                    }
                    dp[i] = dp[i-1] + 2 + before_res;
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
