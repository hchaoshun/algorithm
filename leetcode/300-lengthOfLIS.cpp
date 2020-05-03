//dp[i] 表示目前i的最长递增序列数，
//遍历j 0-i，if nums[j] >= nums[i] 跳过, else nums[i] 在 nums[j]之后，dp[i] = dp[j] + 1
//此时寻找0-i中dp[i]的最大值,转移方程： dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};
