//这不是一个最优问题，却可以用dp解决
//dp[i]表示s中0到i是否能拆分成wordDict
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const size_t n = s.size();
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && dic.find(s.substr(j, i-j)) != dic.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
