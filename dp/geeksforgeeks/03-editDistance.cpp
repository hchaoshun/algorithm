#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>

using namespace std;

//二维动态规划，模仿lcs问题解决
//dp[i][j]表示word1中[0,i], word2中[0,j]最小变换长度,
//分析"str1c""到"str2d""的变化情况：
//1. 当c == d: min = dp[i-1][j-1]
//2. 当c != d:
//2.1 将c转换为d, min = dp[i-1][j-1] + 1
//2.2 删除c, min = dp[i-1][j] + 1
//2.3 删除d, min = dp[i][j-1] + 1
//综合2.1,2.2,2.3 min = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
size_t editDistance(const string& str1, const string& str2) {
  const size_t n1 = str1.size();
  const size_t n2 = str2.size();
  vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
  for (size_t i = 0; i <= n1; ++i) {
    dp[i][0] = i;
  }
  for (size_t j = 0; j <= n2; ++j) {
    dp[0][j] = j;
  }

  for (size_t i = 1; i < n1+1; ++i) {
    for (size_t j = 1; j < n2+1; ++j) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        int min_num = min(dp[i-1][j], dp[i][j-1]);
        dp[i][j] = min(min_num, dp[i-1][j-1]) + 1;
      }
    }
  }
  return dp[n1][n2];
}

int main() {

  cout << editDistance("un", "atur") << endl;
  return 0;
}
