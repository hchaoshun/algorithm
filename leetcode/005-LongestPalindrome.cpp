//像滑动窗口一样，依次找窗口为2,3...的字串是否是回文，这样遍历到最后的最大窗口就是最终结果
//bool dp[i][j] 记录i到j的字串是否是回文,
//dp[i][j] = (s[i] == s[j] && (dp[i+1][j-1] || j - 1 == 1))


//todo 从大到小查找会更快
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n == 0) return "";
        //dp存储从i到j是否是回文
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        int start = 0, len = 1;
        //从长度2开始更新dp
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && (l == 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    start = i;
                    len = l;
                }
            }
        }
        return s.substr(start, len);
    }
};
