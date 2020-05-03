//dfs,会超时
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(coins, amount, result, path, 0);
        sort(result.begin(), result.end(), [](const vector<int> &vec1, const vector<int> &vec2) {
            return vec1.size() < vec2.size();
        });
        return result.empty() ? -1 : result[0].size();

    }

    void dfs(vector<int> &coins, int amount, vector<vector<int>> &result, vector<int> &path, int index) {
        if (amount == 0) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < coins.size(); i++) {
            if (coins[i] > amount) continue;
            path.push_back(coins[i]);
            dfs(coins, amount - coins[i], result, path, i);
            path.pop_back();
        }
    }
};

//dp存储金额为i时的最少硬币个数
//dp[i] = min(dp[i-cj]) + 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_amount = amount + 1;
        vector<int> dp(amount+1, max_amount);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i < coins[j]) continue;
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount] == max_amount ? -1 : dp[amount];
    }
};
