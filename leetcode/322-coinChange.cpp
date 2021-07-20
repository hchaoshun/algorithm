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
//dp[i] = min(dp[i-cj] + 1)
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


//首先令所有初始值为-1
//寻找dp最小值：dp[i] = min(dp[i], dp[i - coins[j]] + 1)
//注意1: i - coins[j]没有在dp中赋值过（-1）表示此种情况不存在
//注意2: 第一次初始化不需要比最小值（因为此时默认值是-1），所以需要is_first参数
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0) return 0;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            bool is_first = true;
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (is_first) {
                        dp[i] = dp[i - coins[j]] + 1;
                        is_first = false;
                    } else {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};
