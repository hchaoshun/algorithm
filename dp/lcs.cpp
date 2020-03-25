//递归写法
class Solution {
public:
    int lcs(string s1, string s2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (s1[m-1] == s2[n-1]) {
            return lcs(s1, s2, m-1, n-1) + 1;
        } else {
            return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));
        }
    }
};

//dp[i][j] 表示长度为i的s1和长度为j的s2的lcs长度
//dp[0][0]不用
class Solution {
public:
    int lcs(string s1, string s2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

//lcs连续公共子序列
class Solution {
public:
    int lcs(const string &s1, const string &s2) {
        const int m = s1.size();
        const int n = s2.size();

        if (m == 0 || n == 0) return 0;
        int ret = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (ret < dp[i][j]) ret = dp[i][j];
            }
        }
        return ret;
    }
};
