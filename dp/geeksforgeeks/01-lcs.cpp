#include <iostream>
#include <vector>
#include <string>

using namespace std;

//dp[i][j], 当 s[i]==s[j], dp[i][j] = dp[i-1][j-1] + 1,
//当s[i] != s[j], dp[i][j] = max(dp[i-1][j], dp[i][j-1])
size_t lcs(const string& s1, const string& s2) {
  const size_t m = s1.size();
  const size_t n = s2.size();
  size_t result = 0;

  vector<vector<size_t>> dp(m+1, vector<size_t>(n+1, 0));

  for (size_t i = 1; i < m+1; ++i) {
    for (size_t j = 1; j < n+1; ++j) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}



int main() {
  string s1 = "AGGTAB", s2 = "GXTXAYB";
  cout << lcs(s1, s2) << endl;

  return 0;
}

