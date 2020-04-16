//有n件物品和容量为m的背包 给出i件物品的重量以及价值 求解让装入背包的物品重量不超过背包容量 且价值最大

//用dp[i][j] 表示将前i个物体放进容量为j的背包里得到的最大价值
//分两种情况
//1. 不放第i个物体：此时总价值为dp[i-1][j]
//2. 放第i个物体：此时总价值为v[i] + dp[i-1][j-w[i]]
//综上，状态转移方程为dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]])
class Solution {
 public:
  int package(const vector<int> &w, const vector<int> &v, int c) {
    const int n = w.size();
    vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
    for (int i = 0; i <= c; i++) {
      dp[0][i] = w[0] <= i ? v[0] : 0;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= c; j++) {
        if (w[j] <= j) {
          dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
        }
      }
    }

    return dp[n-1][c];
  }
};
