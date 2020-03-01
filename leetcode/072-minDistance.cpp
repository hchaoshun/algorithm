//二维动态规划，模仿lcs问题解决
//dp[i][j]表示word1中[0,i], word2中[0,j]最小变换长度,
//分析"str1c""到"str2d""的变化情况：
//1. 当c == d: min = dp[i-1][j-1]
//2. 当c != d:
//2.1 将c转换为d, min = dp[i-1][j-1] + 1
//2.2 删除c, min = dp[i-1][j] + 1
//2.3 删除d, min = dp[i][j-1] + 1
//综合2.1,2.2,2.3 min = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t len1 = word1.size();
        const size_t len2 = word2.size();
        int dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));

        for (size_t i = 0; i <= len1; i++)
            dp[i][0] = i;
        for (size_t j = 0; j <=len2; j++)
            dp[0][j] = j;
        
        for (size_t i = 1; i <= len1; i++) {
            for (size_t j = 1; j <= len2; j++) {
                int min_num = 0;
                if (word1[i-1] == word2[j-1]) {
                    min_num = dp[i-1][j-1];
                } else {
                    int min1 = min(dp[i-1][j-1], dp[i-1][j]);
                    min_num = min(min1, dp[i][j-1]) + 1;
                }
                dp[i][j] = min_num;
            }
        }
        return dp[len1][len2];
    }
};
