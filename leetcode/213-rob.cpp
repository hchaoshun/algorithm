//只比较nums.begin(), nums.end() - 1和nums.begin() + 1, nums.end()的最大值即可
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(robber(nums1), robber(nums2));
    }

    int robber(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp.back();
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int result = 0;
        for (int i = 0; i < n; ++i) {
            auto it_last = nums.end() - 1;
            vector<int> tmp(nums.begin(), it_last);
            result = max(robber(tmp), result);
            int num = *it_last;
            nums.erase(it_last);
            nums.insert(nums.begin(), num);
        }
        return result;
    }

private:
    int robber(vector<int>& nums) {
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
