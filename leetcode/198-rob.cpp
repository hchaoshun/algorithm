//dp[0] = 0; dp[1] = num[i], dp[2] = max(dp[1], dp[2]);
//dp[i] = max(dp[i-2] + num[i], dp[i-1])
//注意：dp[1] = max(nums[0], nums[1]);
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            int r = 0;
            for (int j = i - 2; j >= 0; --j) {
                r = max(r, dp[j] + nums[i]);
            }
            dp[i] = max(r, dp[i-1]);
        }
        return dp[n-1];
    }
};
