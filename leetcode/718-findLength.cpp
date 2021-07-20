//子数组连续，子序列不连续
//遍历时必须从下标0开始，不然首位会漏掉
//为了解决dp[i][j] = dp[i-1][j-1] + 1 i - 1可能小于0的问题，dp长度为m+1和n+1
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        if (m <= 0 || n <= 0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = 0;
                }
                ret = max(ret, dp[i+1][j+1]);
            }
        }
        return ret;
    }
};
