#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>

using namespace std;

//dp[i] 表示目前i的最长递增序列数，
//遍历j 0-i，if nums[j] >= nums[i] 跳过, else nums[i] 在 nums[j]之后，dp[i] = dp[j] + 1
//此时寻找0-i中dp[i]的最大值,转移方程： dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)。

//错解，没有考虑到dp数组应该是单调递增
//输入{6,7,9,4,10,5,6}时错误
size_t lis_error(const vector<size_t>& vec) {
  const size_t n = vec.size();
  if (n == 0 || n == 1) {
    return n;
  }

  vector<size_t> dp(n, 1);
  for (size_t i = 1; i < n; ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (vec[j] < vec[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  return dp[n-1];
}

size_t lis(const vector<size_t>& vec) {
  const size_t n = vec.size();
  if (n == 0 || n == 1) {
    return n;
  }

  vector<size_t> dp(n, 1);
  size_t result = 1;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (vec[j] < vec[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      result = max(result, dp[i]);
    }
  }
  return result;
}

int main() {
  vector<std::size_t> vec {6,7,9,4,10,5,6};
  cout << lis(vec) << endl;
  return 0;
}
