class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        dfs(nums, S, 0, 0, count);
        return count;
    }

    void dfs(vector<int> &nums, int S, int index, int sum, int &count) {
        if (index == nums.size()) {
            if (sum == S) {
                count++;
            }
            return;
        }

        dfs(nums, S, index+1, sum + nums[index], count);
        dfs(nums, S, index+1, sum - nums[index], count);
    }
};
