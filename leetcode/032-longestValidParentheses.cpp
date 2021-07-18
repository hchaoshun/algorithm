//注意：此题求的是最长有效括号的长度
//dp[i]表示以下标为 i 的字符结尾的最长有效子字符串的长度
//if s[i] == '(' :
//    dp[i] = 0
//if s[i] == ')' :
//    if s[i - 1] == '(' :
//        dp[i] = dp[i - 2] + 2 #要保证i - 2 >= 0
//
//  i - dp[i - 1] - 1表示与s[i]匹配的最长括号下标, 形如((......)),其中内括号的最大长度是dp[i-1],所以最左边的位置是i - dp[i - 1] - 1
//    注意如果之前的子序列是形如 (...)(...) 这种序列，那么当前位置的最长有效括号长度还需要加上这一段dp[i - dp[i - 1] - 2]
//    if s[i - 1] == ')' and s[i - dp[i - 1] - 1] == '(' :
//        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 #要保证i - dp[i - 1] - 2 >= 0



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
